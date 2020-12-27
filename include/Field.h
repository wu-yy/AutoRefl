//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_FIELD_H_
#define TEST_DEMO_INCLUDE_FIELD_H_
#include "NamedValue.h"
#include "AttrList.h"
#include "detail/FieldTraits.h"
#include "Util.h"

template<typename Name, typename T, typename AList>
struct Field : FieldTraits<T>, NamedValue<Name, T> {
  static_assert(IsInstance<AList, AttrList>::value);
  static_assert(!std::is_void_v<T>);

  AList attrs;

  constexpr Field(Name name, T value, AList attrs = {})
      : NamedValue<Name, T>{ name, value }, attrs{ attrs }{}
};

template<typename Name, typename T, typename AList>
Field(Name, T, AList)->Field<Name, T, AList>;

template<typename Name, typename T>
Field(Name, T)->Field<Name, T, AttrList<>>;

#endif //TEST_DEMO_INCLUDE_FIELD_H_
