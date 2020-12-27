//
// Created by wuyongyu02 on 2020/12/27.
//

#ifndef TEST_DEMO_SRC_AUTOREFL_METAGENERATOR_H_
#define TEST_DEMO_SRC_AUTOREFL_METAGENERATOR_H_

#pragma once

#include "Meta.h"

#include <memory>
class MetaGenerator {
 public:
  MetaGenerator();
  ~MetaGenerator();
  MetaGenerator(MetaGenerator&&) noexcept;
  MetaGenerator& operator=(MetaGenerator&&) noexcept;

  std::vector<TypeMeta> Parse(std::string_view cppCode);
 private:
  struct Impl;
  std::unique_ptr<Impl> pImpl;
};
#endif //TEST_DEMO_SRC_AUTOREFL_METAGENERATOR_H_
