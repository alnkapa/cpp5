#pragma once
#include <iostream>

struct MyIp {
  int m_num0{};
  int m_num1{};
  int m_num2{};
  int m_num3{};
  MyIp(int num0, int num1, int num2, int num3);
  friend std::ostream &operator<<(std::ostream &, const MyIp &);
  bool operator<(const MyIp &b) const;
};
