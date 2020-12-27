#include <iostream>
#include <thread>
#include "include/FiledTraits.h"

template<class>
struct Test;

template<class U, class T>
struct Test<T U::*> {
  using member = T;

};
class FuncA{
 public:
  int print()  & {
    a=12;
    return 0;
  }
  int a;
};

int f();

template<class T>
int f2(T& a){
  a=14;

}

int f3(int&& a) {
  int &v = a;
  std::cout << "a1:" << a << std::endl;
  v = 120;
}

int f3(int& a) {
  std::cout << "a2:" << a << std::endl;
}

template<class T>
int getfunc(T&&t)  {
  f3(std::forward<T&&>(t));
}

class C {
 public:
    C() {
      d = new int{78};
      c = 1;
      std::cout << "construct C" << std::endl;
    }

    C operator = (const C& d) {
      std::cout << "operator=" << std::endl;
      c = d.c;
    }

    C(const C& d) {
      std::cout << "const C&" << std::endl;
      c = d.c;
    }
     C(const C&& d) {
       std::cout << "const C&&" << std::endl;
       c = d.c;
    }
 public:
    int c;
    int* d;
};

template<class T>
void swap(T&a, T&b) {
  T tmp(std::move(a));
  a = std::move(b);
  b = std::move(tmp);

}

#include <stdio.h>
#include <unistd.h>

template<typename Name, typename T>
struct NamedValue;

template<typename Name, typename T>
struct NamedValueBase {
  static constexpr std::string_view name = Name::value;
  static constexpr bool has_value = !std::is_void_v<T>;

  template<typename Str>
  static constexpr bool NameIs(Str = {}) noexcept {
    return std::is_same_v<Str, Name>;
  }

  template<typename U>
  static constexpr bool ValueTypeIs() noexcept {
    return std::is_same_v<T, U>;
  }

  template<typename U>
  static constexpr bool ValueTypeIsSameWith(U) noexcept {
    return ValueTypeIs<U>();
  }
};

// 1.实现
template<typename Name, typename T>
struct NamedValue : NamedValueBase<Name, T> {
  T value;

  constexpr NamedValue(Name, T value) : value{ value } {}

  template<typename U>
  constexpr bool operator==(U v) const {
    if constexpr (std::is_same_v<T, U>)
      return value == v;
    else
      return false;
  }
};

// 2.特化
template<typename Name>
struct NamedValue<Name, void> : NamedValueBase<Name, void> {
  constexpr NamedValue(Name){
    std::cout << "Name1" << std::endl;
  }
  constexpr NamedValue(Name, Name) {
    std::cout << "Name2" << std::endl;
  }
  template<typename U>
  constexpr bool operator==(U) const { return false; }

  static constexpr void FinValue(Name) {
    std::cout << "Find value" << std::endl;
  }
};

// 3.类构造
template<typename Name>
NamedValue(Name)->NamedValue<Name, void>;

template<typename Name>
NamedValue(Name, Name)->NamedValue<Name, void>;

// Test
class A {
 public:
  constexpr A(){}
  A(int) {}
};


// [summary]
// attribute for field, class, enum
// [member]
// T value (T == void -> no value)
template<typename Name, typename T>
struct Attr;

using Char = char;
template<typename Name, typename Char, std::size_t N>
Attr(Name, const Char(&)[N])->Attr<Name, std::basic_string_view<Char>>;

template<typename Name>
Attr(Name)->Attr<Name, void>;

auto f() -> int {
  return  12;
}


class test{
 public:
   test(){
      a= 12;
  }

  constexpr int operator + (const test& rhs){
    return 1;
  }
  int a;
  template<class T>
   constexpr bool find_test(T t) {
     std::cout << "find_test..." << std::endl;
      return false;
   }
};

void PP(char(&a)[12]) {
  a[0]= '1';
  std::cout << "a:" << a << std::endl;
}

#include <vector>
int main() {
  std::vector<int> wv {1,2 ,3};
//  std::apply([&](int e){
//       e= 2;
//    }, wv);
  auto v = std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<std::tuple<int> > >>{};
  std::tuple<int, int> t = {12, 12};
  std::cout << std::get<0>(std::forward<std::tuple<int, int>>(t)) << std::endl;
  return 0;
}
