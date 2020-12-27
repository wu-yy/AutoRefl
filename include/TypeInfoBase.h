//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_TYPEINFOBASE_H_
#define TEST_DEMO_INCLUDE_TYPEINFOBASE_H_

#include "BaseList.h"

#include <UTemplate/Name.h>

template<typename T, typename... Bases>
struct TypeInfoBase {
  using Type = T;
  static constexpr std::string_view name = type_name<T>().value;
  static constexpr BaseList bases = { Bases{}... };

  template<typename Derived>
  static constexpr auto&& Forward(Derived&& derived) noexcept;

  static constexpr auto VirtualBases();

  template<typename Init, typename Func>
  static constexpr auto DFS_Acc(Init&& init, Func&& func);

  template<typename Func>
  static constexpr void DFS_ForEach(Func&& func);

  template<typename U, typename Func>
  static constexpr void ForEachVarOf(U&& obj, Func&& func);
};
#include "detail/TypeInfoBase.inl"
#endif //TEST_DEMO_INCLUDE_TYPEINFOBASE_H_
