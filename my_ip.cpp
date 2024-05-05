#include "my_ip.h"
#include <tuple>

std::ostream &operator<<(std::ostream &os, const MyIp &pt) {
  os << pt.m_num0 << "." << pt.m_num1 << "." << pt.m_num2 << "." << pt.m_num3;
  return os;
}

MyIp::MyIp(int num0, int num1, int num2, int num3)
    : m_num0{num0}, m_num1{num1}, m_num2{num2}, m_num3{num3} {};

bool MyIp::operator<(const MyIp &b) const {
  return std::tie(m_num0, m_num1, m_num2, m_num3) >
         std::tie(b.m_num0, b.m_num1, b.m_num2, b.m_num3);
}