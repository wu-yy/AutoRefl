//
// Created by wuyongyu02 on 2020/12/26.
//

#ifndef TEST_DEMO_INCLUDE_FILEDTRAITS_H_
#define TEST_DEMO_INCLUDE_FILEDTRAITS_H_
#include <type_traits>

template<class Obj, class Value, bool isStatic, bool isFunction>
struct FieldTraitsBase {
  using objetc_type = Obj;
  using value_type = Value;
  static  constexpr  bool is_static =isStatic;
  static  constexpr  bool is_func = isFunction;
};

template<class Obejct>
struct FieldTraits;

// non-static member poiter
// Object is class, T is function of the member of Object
template<class Object, class T>
struct FieldTraits<T Object::* > : FieldTraitsBase<Object, T, false, std::is_function<T>::value> {
};

#endif //TEST_DEMO_INCLUDE_FILEDTRAITS_H_
