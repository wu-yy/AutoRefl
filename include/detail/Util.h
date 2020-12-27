//
// Created by wuyongyu02 on 2020/12/26.
//

#ifndef TEST_DEMO_INCLUDE_DETAIL_UTIL_H_
#define TEST_DEMO_INCLUDE_DETAIL_UTIL_H_
#include <utility>
#include <cassert>
template<typename T, template<typename ...> class U>
struct IsInstance : std::false_type {};

template<template<class ...>class U, class ... Ts>
    struct  IsInstance<U<Ts...>, U> : std::true_type {};

template<class Ints>
struct IntegerSequenceTraits;

template<class T, T N0, T...Ns>
struct IntegerSequenceTraits<std::integer_sequence<T, N0, Ns...>> {
  static constexpr  std::size_t  head=N0;
  static constexpr  auto tail = std::integer_sequence<T, Ns...>{};
};
template<class Signature>
struct ConstructorWrapper;

template<class T, class... Args>
struct  ConstructorWrapper<T(Args...)> {
  static constexpr auto run() {
    return static_cast<void(*)(T*, Args...)>(
        [](T*ptr, Args...args){
          new(ptr) T{std::forward<Args>(args)...};
        }
        );
  }
};

// Signature : T(Args...)
// ->
// void(*)(T*, Args...)
template<typename Signature>
constexpr auto WrapConstructor() {
  return ConstructorWrapper<Signature>::run();
}

template<typename T>
constexpr auto WrapDestructor() {
  return static_cast<void(*)(T*)>(
      [](T* ptr) {
        ptr->~T();
      }
  );
}

#endif //TEST_DEMO_INCLUDE_DETAIL_UTIL_H_
