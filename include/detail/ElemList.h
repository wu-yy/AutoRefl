//
// Created by wuyongyu02 on 2020/12/26.
//

#ifndef TEST_DEMO_INCLUDE_DETAIL_ELEMLIST_H_
#define TEST_DEMO_INCLUDE_DETAIL_ELEMLIST_H_
#include "../Util.h"

#include <array>
template<typename List, typename Func, typename Acc, std::size_t... Ns, bool... masks>
constexpr auto Accumulate(const List& list, Func&& func, Acc acc, std::index_sequence<Ns...>, std::integer_sequence<bool, masks...>) {
  if constexpr (sizeof...(Ns) > 0) {
    using IST_N = IntegerSequenceTraits<std::index_sequence<Ns...>>;
    if constexpr (sizeof...(masks) > 0) {
      using IST_Mask = IntegerSequenceTraits<std::integer_sequence<bool, masks...>>;
      if constexpr (IST_Mask::head == true) {
        return Accumulate(
            list,
            std::forward<Func>(func),
            std::forward<Func>(func)(std::move(acc), list.template Get<IST_N::head>()),
            IST_N::tail,
            IST_Mask::tail
        );
      }
      else { // mask is false
        return Accumulate(
            list,
            std::forward<Func>(func),
            std::move(acc),
            IST_N::tail,
            IST_Mask::tail
        );
      }
    }
    else { // default true
      return Accumulate(
          list,
          std::forward<Func>(func),
          std::forward<Func>(func)(std::move(acc), list.template Get<IST_N::head>()),
          IST_N::tail,
          std::integer_sequence<bool>{}
      );
    }
  }
  else
    return acc;
}

template<typename List, typename Func, std::size_t... Ns>
constexpr std::size_t FindIf(const List& list, Func&& func, std::index_sequence<Ns...>) {
  if constexpr (sizeof...(Ns) > 0) {
    using IST = IntegerSequenceTraits<std::index_sequence<Ns...>>;
    return std::forward<Func>(func)(list.template Get<IST::head>()) ?
           IST::head : FindIf(list, std::forward<Func>(func), IST::tail);
  }
  else
    return static_cast<std::size_t>(-1);
}

template<typename... Elems>
template<bool... masks, typename Init, typename Func>
constexpr auto ElemList<Elems...>::Accumulate(Init init, Func&& func) const {
  return Accumulate(
      *this,
      std::forward<Func>(func),
      std::move(init),
      std::make_index_sequence<size>{},
      std::integer_sequence<bool, masks...>{}
  );
}

template<typename... Elems>
template<bool... masks, typename Func>
constexpr void ElemList<Elems...>::ForEach(Func&& func) const {
  Accumulate<masks...>(0, [&](auto, const auto& field) {
    std::forward<Func>(func)(field);
    return 0;
  });
}


template<typename... Elems>
template<typename Func>
constexpr std::size_t ElemList<Elems...>::FindIf(Func&& func) const {
  return FindIf(*this, std::forward<Func>(func), std::make_index_sequence<size>{});
}

template<typename... Elems>
template<typename Name>
constexpr const auto& ElemList<Elems...>::Find(Name) const {
  if constexpr (sizeof...(Elems) > 0) {
    constexpr std::size_t idx = []() {
      constexpr std::array names{ Elems::name... };
      for (std::size_t i = 0; i < names.size(); i++) {
        if (Name::value == names[i])
          return i;
      }
      return static_cast<std::size_t>(-1);
    }();
    static_assert(idx != static_cast<std::size_t>(-1));
    return Get<idx>();
  }
  else
    return static_cast<std::size_t>(-1);
}

template<typename... Elems>
template<typename T>
constexpr std::size_t ElemList<Elems...>::FindValue(const T& value) const {
  return FindIf([&value](const auto& e) { return e.value == value; });
}

template<typename... Elems>
template<typename T, typename Str>
constexpr const T* ElemList<Elems...>::ValuePtrOfName(Str name) const {
  const T* value = nullptr;
  FindIf([name, &value](const auto& ele) {
    using Elem = std::decay_t<decltype(ele)>;
    if constexpr (Elem::template ValueTypeIs<T>()) {
      if (ele.name == name) {
        value = &ele.value;
        return true;
      }
      else
        return false;
    }
    else
      return false;
  });
  return value;
}

template<typename... Elems>
template<typename T, typename Char>
constexpr std::basic_string_view<Char> ElemList<Elems...>::NameOfValue(const T& value) const {
  std::basic_string_view<Char> name;
  FindIf([value, &name](auto ele) {
    using Elem = std::decay_t<decltype(ele)>;
    if constexpr (Elem::template ValueTypeIs<T>()) {
      if (ele.value == value) {
        name = Elem::name;
        return true;
      }
      else
        return false;
    }
    else
      return false;
  });
  return name;
}

template<typename... Elems>
template<typename Name>
constexpr bool ElemList<Elems...>::Contains(Name) {
  return (Elems::template NameIs<Name>() || ...);
}

template<typename... Elems>
template<std::size_t N>
constexpr const auto& ElemList<Elems...>::Get() const {
  return std::get<N>(elems);
}

template<typename... Elems>
template<typename Elem>
constexpr auto ElemList<Elems...>::Push(Elem e) const {
  return std::apply([e](const auto&... elems) {
    return ElemList<Elems..., Elem>{ elems..., e };
  }, elems);
}

template<typename... Elems>
template<typename Elem>
constexpr auto ElemList<Elems...>::Insert(Elem e) const {
  if constexpr ((std::is_same_v<Elems, Elem> || ...))
    return *this;
  else
    return Push(e);
}


#endif //TEST_DEMO_INCLUDE_DETAIL_ELEMLIST_H_
