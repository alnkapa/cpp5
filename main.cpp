#include <iostream>
#include <array>

template <
    typename T,
    typename = std::enable_if_t<std::is_integral_v<T>, bool>>
constexpr void print_ip(const T &in)
{
  // std::array<int, sizeof(T)> arr{};
  for (size_t i = sizeof(T); i != 0; i--)
  {
    // arr[i] = static_cast<int>(static_cast<uint8_t>(in >> i * 8));
    std::cout << static_cast<int>(static_cast<uint8_t>((in >> i * 8) & 0xff)) << ".";
  }
  std::cout << std::endl;
  for (size_t i = 0; i < sizeof(T); i++)
  {
    // arr[i] = static_cast<int>(static_cast<uint8_t>(in >> i * 8));
    std::cout << static_cast<int>(static_cast<uint8_t>((in >> i * 8) & 0xff)) << ".";
  }
  // for (auto &v : arr)
  // {
  //   std::cout << v << ".";
  // }
  std::cout << std::endl;
  // switch (sizeof(T) * 8)
  // {
  // case INT16_WIDTH:
  //   std::cout << "HI" << std::endl;
  //   break;
  // default:
  //   std::cout << static_cast<int>(static_cast<uint8_t>(in)) << std::endl;
  //   break;
  // }
}

int main()
{
  print_ip(int8_t{-1});                   // 255
  print_ip(int16_t{0});                   // 0.0
  print_ip(int16_t{264});                 // 0.0
  print_ip(int32_t{2130706433});          // 127.0.0.1
  print_ip(int64_t{8875824491850138409}); // 123.45.67.89.101.112.131.41
  //  print_ip(std::string{“Hello, World !”});        // Hello, World!
  //  print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
  //  print_ip(std::list<shot>{400, 300, 200, 100});  // 400.300.200.100
  //  print_ip(std::make_tuple(123, 456, 789, 0));    // 123.456.789.0
  return 0;
}