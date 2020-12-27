//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_ELEMLIST_H_
#define TEST_DEMO_INCLUDE_ELEMLIST_H_
#include "NamedValue.h"

#include <tuple>

// Elems is named value
template<class ... Elems>
struct  ElemList {
  std::tuple<Elems...> elems;

  constexpr ElemList(Elems... args) : elems{args...} {}

  template<bool ... masks, typename Acc, typename Func>
  constexpr auto Accumulate(Acc acc, Func&& func) const ;

  template<bool ... masks, class Func>
  constexpr void ForEach(Func&& func) const;

  template<typename Func>
  constexpr std::size_t FindIf(Func&& func) const;

  template<typename Name>
  constexpr const auto& Find(Name = {}) const;

  template<typename T>
  constexpr std::size_t FindValue(const T& value) const;

  template<typename T, typename Str>
  constexpr const T* ValuePtrOfName(Str name) const;

  template<typename T, typename Str>
  constexpr const T& ValueOfName(Str name) const { return *ValuePtrOfName<T>(name); }

  template<typename T, typename Char = char>
  constexpr std::basic_string_view<Char> NameOfValue(const T& value) const;

  template<typename Name>
  static constexpr bool Contains(Name = {});

  template<std::size_t N>
  constexpr const auto& Get() const;

  template<typename Elem>
  constexpr auto Push(Elem e) const;

  template<typename Elem>
  constexpr auto Insert(Elem e) const;
  // value must be constexpr
  // C++20 support string literal as template arguments
  #define USRefl_ElemList_GetByValue(list, value) list.Get<list.FindValue(value)>()
};

#include "detail/ElemList.h"

#endif //TEST_DEMO_INCLUDE_ELEMLIST_H_
