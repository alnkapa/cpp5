#include "my_allocator11.h"
#include "my_list.h"
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
using pair_t = std::pair<const int, int>;
int main() {
  {
    typedef std::map<int, int, std::less<int>, MyAllocator17<pair_t, 10>> map_t;
    map_t o3Map;
    for (int i = 0; i < 10; i++) {
      try {
        o3Map.emplace(i, factorial(i));
      } catch (const std::exception &e) {
        std::cout << "exception:" << e.what() << "\n";
      };
    }
    for (map_t::const_iterator it = o3Map.begin(); it != o3Map.end(); it++) {
      std::cout << (*it).first << " " << (*it).second << "\n";
    }
  }
  {
    typedef MyList<int, MyAllocator17<int, 10>> my_list_t;

    my_list_t list;
    //  Создаем список
    //MyList<int> list;

    // Добавляем элементы в список
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Печатаем элементы списка
    std::cout << "List elements:";
    for (auto it = list.begin(); it != list.end(); ++it) {
      std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Проверяем методы size и empty
    std::cout << "List size: " << list.size() << std::endl;
    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No")
              << std::endl;

    // Удаляем элементы из списка
    list.pop_back();
    list.pop_back();

    // Проверяем методы size и empty после удаления элементов
    std::cout << "List size after removal: " << list.size() << std::endl;
    std::cout << "Is list empty after removal? "
              << (list.empty() ? "Yes" : "No") << std::endl;

    // Удаляем элементы из списка
    list.pop_back();

    // Проверяем методы size и empty после удаления элементов
    std::cout << "List size after removal: " << list.size() << std::endl;
    std::cout << "Is list empty after removal? "
              << (list.empty() ? "Yes" : "No") << std::endl;

    // return 0;

    // for (int i = 0; i < 10; i++) {
    //   try {
    //     list.push_back(i);
    //   } catch (const std::exception &e) {
    //     std::cout << "exception:" << e.what() << "\n";
    //   };
    // }
  }
  return 0;
}