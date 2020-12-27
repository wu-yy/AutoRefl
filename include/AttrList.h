//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_ATTRLIST_H_
#define TEST_DEMO_INCLUDE_ATTRLIST_H_
#include "ElemList.h"
template<typename... Attrs>
struct AttrList : ElemList<Attrs...> {
  //static_assert((IsInstance<Attrs, Attr>::value&&...));
  constexpr AttrList(Attrs... attrs)
      : ElemList<Attrs...>{ attrs... } {}
};
#include "Attr.h"


#endif //TEST_DEMO_INCLUDE_ATTRLIST_H_
