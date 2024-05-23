#include "my_allocator03.h"
#include <iostream>
#include <map>

int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}
int main()
{
  {
    // создание экземпляра std::map<int, int>
    std::map<int, int> stdMap;
    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; i++)
    {
      stdMap.emplace(i, factorial(i));
    }
    for (auto &&v : stdMap)
    {
      std::cout << v.first << " " << v.second << "\n";
    }
  }
  {
    // создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10 элементами
    std::map<int, int, std::less<int>, MyAllocator03<int>> o3Map;
    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; i++)
    {
      o3Map.emplace(i, factorial(i));
    }
    for (auto &&v : o3Map)
    {
      std::cout << v.first << " " << v.second << "\n";
    }
  }
  return 0;
}