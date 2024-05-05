#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <tuple>

struct MyIp {
  int m_num0{};
  int m_num1{};
  int m_num2{};
  int m_num3{};
  MyIp(int num0, int num1, int num2, int num3)
      : m_num0{num0}, m_num1{num1}, m_num2{num2}, m_num3{num3} {};
  friend std::ostream &operator<<(std::ostream &os, const MyIp &pt) {
    os << pt.m_num0 << "." << pt.m_num1 << "." << pt.m_num2 << "." << pt.m_num3;
    return os;
  };
};

auto compareIp = [](const MyIp &a, const MyIp &b) {
  return std::tie(a.m_num0, a.m_num1, a.m_num2, a.m_num3) >
         std::tie(b.m_num0, b.m_num1, b.m_num2, b.m_num3);
};

using MySet = std::multiset<MyIp, decltype(compareIp)>;

// загрузить список ip-адресов в память и отсортировать их в обратном
// лексикографическом порядке.
MySet read(std::istream &in) {
  int num0{};
  int num1{};
  int num2{};
  int num3{};
  auto max = std::numeric_limits<std::streamsize>::max();
  MySet sst(compareIp);
  int count{};
  while (!std::cin.eof() && std::cin.peek() != -1) {
    switch (count) {
    case 0:
      in >> num0;
      in.ignore(max, '.');
      count++;
      break;
    case 1:
      in >> num1;
      in.ignore(max, '.');
      count++;
      break;
    case 2:
      in >> num2;
      in.ignore(max, '.');
      count++;
      break;
    case 3:
      in >> num3;
      in.ignore(max, '\n');
      sst.insert(MyIp{num0, num1, num2, num3});
      count = 0;
      break;
    }
  };
  return sst;
}

int main() {
  auto sst{read(std::cin)};
  // выводим полный список адресов после сортировки. Одна строка - один адрес.
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