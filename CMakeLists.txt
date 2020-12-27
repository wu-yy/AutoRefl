cmake_minimum_required(VERSION 3.16)
project(test_demo VERSION 0.1.0)
message(STATUS "[Project] ${PROJECT_NAME}")

include()


set(CMAKE_CXX_STANDARD 17)

add_executable(test_demo main.cpp include/FiledTraits.h include/detail/FieldTraits.h include/detail/Attr.inl include/detail/ElemList.h include/detail/Util.h include/Attr.h include/NamedValue.h include/ElemList.h include/Util.h include/Field.h include/AttrList.h include/FieldList.h include/Base.h include/TypeInfo.h include/BaseList.h include/TypeInfoBase.h include/config.h include/Refl.h src/AutoRefl/Meta.h src/AutoRefl/Meta.cpp src/AutoRefl/MetaGenerator.h src/AutoRefl/MetaGenerator.cpp src/AutoRefl/TypeInfoGenerator.h src/AutoRefl/TypeInfoGenerator.cpp src/AutoRefl/main.cpp src/EMPTY/main.cpp)