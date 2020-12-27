//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_FIELDLIST_H_
#define TEST_DEMO_INCLUDE_FIELDLIST_H_
#include "Field.h"
#include "ElemList.h"
#include "Util.h"
// Field's (name, value_type) must be unique
template<typename... Fields>
struct FieldList : ElemList<Fields...> {
  //static_assert((IsInstance<Fields, Field>::value&&...));
  constexpr FieldList(Fields... fields) : ElemList<Fields...>{ fields... } {};
};

#endif //TEST_DEMO_INCLUDE_FIELDLIST_H_
