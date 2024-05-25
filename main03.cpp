#include "my_allocator03.h"
#include <exception>
#include <iostream>
#include <map>
#include <utility>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
int main() {

  MyAllocator03<int, 10> alloc1;
  MyAllocator03<int, 10> alloc2;
  MyAllocator03<float, 10> alloc3;

  std::cout << (alloc1 == alloc2) << std::endl; // Должно вывести 1 (true)
  std::cout << (alloc1 != alloc2) << std::endl; // Должно вывести 0 (false)
  std::cout << (alloc1 == alloc3) << std::endl; // Должно вывести 0 (false)
  std::cout << (alloc1 != alloc3) << std::endl; // Должно вывести 1 (true)

  typedef std::pair<const int, int> pair_t;
  {
    // создание экземпляра std::map<int, int>
    std::map<int, int> stdMap;
    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение -
    // факториал ключа
    for (int i = 0; i < 10; i++) {
      stdMap.insert(pair_t(i, factorial(i)));
    }
  }
  {
    // создание экземпляра std::map<int, int> с новым аллокатором, ограниченным
    // 10 элементами
    typedef std::map<int, int, std::less<int>, MyAllocator03<pair_t, 10> > map_t;
    map_t o3Map;
    for (int i = 0; i < 14; i++) {
      try {
        o3Map.insert(pair_t(i, factorial(i)));
      } catch (const std::exception &e) {
        std::cout << "exception:" << e.what() << "\n";
      };
    }
    for (map_t::const_iterator it = o3Map.begin(); it != o3Map.end(); it++) {
      std::cout << (*it).first << " " << (*it).second << "\n";
    }
  }
  return 0;
}