//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_BASELIST_H_
#define TEST_DEMO_INCLUDE_BASELIST_H_

#include "Base.h"
#include "ElemList.h"
// #include "detail/Util.h"

template<typename... Bases>
struct BaseList : ElemList<Bases...> {
  // static_assert((detail::IsInstance<Bases, Base>::value&&...));
  constexpr BaseList(Bases... bases)
      : ElemList<Bases...>{ bases... } {};
};
#endif //TEST_DEMO_INCLUDE_BASELIST_H_
