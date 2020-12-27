//
// Created by wuyongyu02 on 2020/12/26.
//

#ifndef TEST_DEMO_INCLUDE_DETAIL_FIELDTRAITS_H_
#define TEST_DEMO_INCLUDE_DETAIL_FIELDTRAITS_H_
#pragma once

#include <type_traits>

template<typename T>
struct FieldTraits;

template<typename Obj, typename Value, bool isStatic, bool isFunction>
struct FieldTraitsBase {
  using object_type = Obj;
  using value_type = Value;
  static constexpr bool is_static = isStatic;
  static constexpr bool is_func = isFunction;
};

// non-static member pointer
template<typename Object, typename T>
struct FieldTraits<T Object::*>
    : FieldTraitsBase<Object, T, false, std::is_function_v<T>> {};

// static member pointer
template<typename T>
struct FieldTraits<T*>
    : FieldTraitsBase<void, T, true, std::is_function_v<T>> {};

// enum / static constexpr
template<typename T>
struct FieldTraits
    : FieldTraitsBase<void, T, true, false> {};

#endif //TEST_DEMO_INCLUDE_DETAIL_FIELDTRAITS_H_
