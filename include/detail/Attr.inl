//
// Created by wuyongyu02 on 2020/12/26.
//

#ifndef TEST_DEMO_INCLUDE_DETAIL_ATTR_INL_
#define TEST_DEMO_INCLUDE_DETAIL_ATTR_INL_
template<typename Name, typename T>
struct Attr : NamedValue<Name, T> {
  constexpr Attr(Name name, T value)
      : NamedValue<Name, T>{ name, value } {}
};

template<typename Name>
struct Attr<Name, void> : NamedValue<Name, void> {
  constexpr Attr(Name name) : NamedValue<Name, void>{ name } {}
};

#endif //TEST_DEMO_INCLUDE_DETAIL_ATTR_INL_
