#include <array>
#include <cstdint>
#include <iostream>
#include <list>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
namespace impl {
/**
 * проверка на метод c_str()
 */
namespace c_str {
template <typename T>
static auto check(int) -> decltype(std::declval<T>().c_str(), std::true_type());
template <typename> static std::false_type check(...);
template <typename U> struct has {
  static constexpr bool value = decltype(check<U>(int{}))::value;
};
} // namespace c_str

/**
 * проверка на оператор <<
 */
namespace operator_shift {
template <typename T>
static auto check(int)
    -> decltype(std::declval<std::ostream &>() << std::declval<T>(),
                std::true_type());
template <typename> static std::false_type check(...);
template <typename U> struct has {
  static constexpr bool value = decltype(check<U>(int{}))::value;
};
} // namespace operator_shift
/**
 * проверка на begin() и end()
 */
namespace begin_end {
template <typename T>
static auto check(int) -> decltype(std::declval<T>().begin(),
                                   std::declval<T>().end(), std::true_type());

template <typename> static std::false_type check(...);

template <typename U> struct has {
  static constexpr bool value = decltype(check<U>(int{}))::value;
};
} // namespace begin_end
namespace iteration3 {
/**
 * вывод любых контейнеров
 */
template <typename T,
          typename = std::enable_if_t<begin_end::has<T>::value, bool>>
constexpr void print_ip(const T &in, int) {
  bool is_point = false;
  for (auto it = in.begin(); it != in.end(); it++) {
    if (is_point) {
      std::cout << ".";
    } else {
      is_point = true;
    }
    std::cout << (*it);
  }
  std::cout << std::endl;
}
/**
 * вывод остальных
 */
template <typename T> constexpr void print_ip(const T &in, long) {
  std::cout << "undefined" << std::endl;
}
} // namespace iteration3
namespace iteration2 {
/**
 * вывод строк
 */
template <typename T, typename = std::enable_if_t<c_str::has<T>::value, bool>>
constexpr void print_ip(const T &in, int) {
  std::cout << in << std::endl;
}
/**
 * вывод остальных
 */
template <typename T> constexpr void print_ip(const T &in, long) {
  iteration3::print_ip(in, int{});
}
} // namespace iteration2
namespace iteration1 {
/**
 * вывод на целочисленных значений
 */
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>, bool>>
constexpr void print_ip(const T &in, int) {
  union {
    T in;
    std::uint8_t arr[sizeof(T)];
  } un;
  un.in = in;
  bool is_point = false;
  for (int i = sizeof(T) - 1; i > -1; i--) {
    if (is_point) {
      std::cout << ".";
    } else {
      is_point = true;
    }
    std::cout << int(un.arr[i]);
  }
  std::cout << std::endl;
}
/**
 * вывод остальных
 */
template <typename T> constexpr void print_ip(const T &in, long) {
  iteration2::print_ip(in, int{});
}
} // namespace iteration1
} // namespace impl
template <typename T> constexpr void print_ip(const T &in) {
  impl::iteration1::print_ip(in, int{});
}

namespace tuple {
/**
 * проверка: все кортежа типы одного типа
 */
// constexpr bool all_same(const std::tuple<> &) {
//   return true; // This is reasonable, right?
// }
template <typename Head, typename... Tail> constexpr bool check(Head, Tail...) {
  return true;
  //(std::is_same_v<Head, Tail> && ...);
}
// template <typename... Types> constexpr bool check(...) { return false; };

template <typename... Types> struct has {
  static constexpr bool value = check<Types...>(Types...);
};
} // namespace tuple

/**
 * для каждого индекса
 */
template <typename T, size_t... N>
constexpr void print_tuple(const T &in, std::index_sequence<N...>) {
  (..., (std::cout << (N == 0 ? "" : ".") << std::get<N>(in)));
}
/**
 * вывод кортежа
 */
template <typename... Types,
          typename = std::enable_if_t<tuple::has<Types...>::value, bool>>
constexpr void print_ip(const std::tuple<Types...> &in) {
  print_tuple(in, std::make_index_sequence<sizeof...(Types)>());
  std::cout << std::endl;
}

int main() {
  print_ip(int8_t{-1});                           // 255
  print_ip(int16_t{0});                           // 0.0
  print_ip(int32_t{2130706433});                  // 127.0.0.1
  print_ip(int64_t{8875824491850138409});         // 123.45.67.89.101.112.131.41
  print_ip(std::string{"Hello, World !"});        // Hello, World!
  print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
  print_ip(std::list<short>{400, 300, 200, 100}); // 400.300.200.100
  print_ip(std::make_tuple(123, 456, 789, 0));    // 123.456.789.0
  print_ip(std::make_tuple(123, 456, 789, "привет")); // ошибка
  return 0;
}