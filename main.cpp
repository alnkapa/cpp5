#include "my_set.h"
#include <iostream>
#include <sstream>

int main() {
  auto sst{read(std::cin)};
  // выводим полный список адресов после сортировки. Одна строка - один
  // адрес.
  for (auto &num : sst) {
    std::cout << num << "\n";
  }
  // выводим список адресов, первый байт которых равен 1.
  for (auto &num : sst) {
    if (num.m_num0 == 1) {
      std::cout << num << "\n";
    }
  }
  // выводим список адресов, первый байт которых равен 46, а второй 70.
  for (auto &num : sst) {
    if (num.m_num0 == 46 && num.m_num1 == 70) {
      std::cout << num << "\n";
    }
  }
  // выводим список адресов, любой байт которых равен 46.
  for (auto &num : sst) {
    if (num.m_num0 == 46 || num.m_num1 == 46 && num.m_num2 == 46 ||
        num.m_num3 == 46) {
      std::cout << num << "\n";
    }
  }
  return 0;
}