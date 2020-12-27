//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_UTIL_H_
#define TEST_DEMO_INCLUDE_UTIL_H_
template<typename Signature>
constexpr auto WrapConstructor();
template<typename T>
constexpr auto WrapDestructor();

#include "detail/Util.h"
#endif //TEST_DEMO_INCLUDE_UTIL_H_
