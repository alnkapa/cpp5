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
    os << int(pt.m_num0) << "." << int(pt.m_num1) << "." << int(pt.m_num2)
       << "." << int(pt.m_num3);
    return os;
  };
  friend bool operator>(const MyIp &c1, const MyIp &c2) {
    if (c1.m_num0 > c2.m_num0) {
      return true;
    }
    if (c1.m_num0 < c2.m_num0) {
      return false;
    }
    if (c1.m_num1 > c2.m_num1) {
      return true;
    }
    if (c1.m_num1 < c2.m_num1) {
      return false;
    }
    if (c1.m_num2 > c2.m_num2) {
      return true;
    }
    if (c1.m_num2 < c2.m_num2) {
      return false;
    }
    if (c1.m_num3 > c2.m_num3) {
      return true;
    }
    if (c1.m_num3 < c2.m_num3) {
      return false;
    }
    return false;
  };
};

auto compareIp = [](const MyIp &a, const MyIp &b) { return a > b; };

using MySet = std::set<MyIp, decltype(compareIp)>;

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
  // for (auto num : sst) {
  //   std::cout << num << "\n";
  // }
  // выводим список адресов, первый байт которых равен 1.
  for (auto num : sst) {
    std::cout << num << "\n";
  }
  return 0;
}