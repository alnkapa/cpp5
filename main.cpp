#include "my_allocator11.h"
#include "my_allocator03.h"
#include <iostream>
#include <map>
#include <exception>
#include <utility>

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
  typedef std::pair<const int, int> pair_t;
  {
    // создание экземпляра std::map<int, int> с новым аллокатором, ограниченным
    // 10 элементами
    typedef std::map<int, int, std::less<int>, MyAllocator03<pair_t, 10> > map_t;
    map_t o3Map;
    for (int i = 0; i < 13; i++)
    {
      try
      {
        std::cout << " i: " << i << std::endl;
        o3Map.insert(pair_t(i, factorial(i)));
      }
      catch (const std::exception &e)
      {
        std::cout << "exception:" << e.what() << "\n";
      };
    }
    for (map_t::const_iterator it = o3Map.begin(); it != o3Map.end(); it++)
    {
      std::cout << (*it).first << " " << (*it).second << "\n";
    }
  }
  return 0;
}