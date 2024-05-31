#include <iostream>
#include <array>
#include <type_traits>
template <
    typename T,
    typename = std::enable_if_t<std::is_integral_v<T>, bool>>
constexpr void print_ip1(const T &in)
{
  union
  {
    T in;
    uint8_t arr[sizeof(T)];
  } un;
  un.in = in;
  bool is_point = false;
  for (int i = sizeof(T) - 1; i > -1; i--)
  {
    if (is_point)
    {
      std::cout << ".";
    }
    else
    {
      is_point = true;
    }
    std::cout << int(un.arr[i]);
  }
  std::cout << std::endl;
}

template <typename T>
static auto check(std::ostream &s, const T &t) -> decltype(s << t, std::true_type{});

template <typename>
static std::false_type check(...);

template <typename U>
struct has_operator_shift
{
  static constexpr bool value = decltype(check<U>(nullptr, nullptr))::value;
};

template <
    typename T,
    typename = std::enable_if_t<has_operator_shift<T>::value, bool>>
constexpr void print_ip(const T &in)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << std::endl;
}

int main()
{
  // print_ip(int8_t{-1});                   // 255
  // print_ip(int16_t{0});                   // 0.0
  // print_ip(int32_t{2130706433});          // 127.0.0.1
  // print_ip(int64_t{8875824491850138409}); // 123.45.67.89.101.112.131.41
  // std::cout << has_operator_shift<std::ostream, std::string>::value << std::endl;
  print_ip(std::string{"Hello, World !"}); // Hello, World!
  //    print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
  //    print_ip(std::list<shot>{400, 300, 200, 100});  // 400.300.200.100
  //    print_ip(std::make_tuple(123, 456, 789, 0));    // 123.456.789.0
  return 0;
}