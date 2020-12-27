//
// Created by wuyongyu02 on 2020/12/26.
//

#ifndef TEST_DEMO_INCLUDE_ATTR_H_
#define TEST_DEMO_INCLUDE_ATTR_H_
#include "NamedValue.h"
#include <string_view>

// [summary]
// attribute for field, class, enum
// [member]
// T value (T == void -> no value)
template<typename Name, typename T>
struct Attr;

template<typename Name, typename Char, std::size_t N>
Attr(Name, const Char(&)[N])->Attr<Name, std::basic_string_view<Char>>;

template<typename Name>
Attr(Name)->Attr<Name, void>;


#endif //TEST_DEMO_INCLUDE_ATTR_H_
