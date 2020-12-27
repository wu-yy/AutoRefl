//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_INCLUDE_BASE_H_
#define TEST_DEMO_INCLUDE_BASE_H_

#include "TypeInfo.h"


template<typename T, bool IsVirtual = false>
struct Base {
  static constexpr auto info = TypeInfo<T>{};
  static constexpr bool is_virtual = IsVirtual;
};

#endif //TEST_DEMO_INCLUDE_BASE_H_
