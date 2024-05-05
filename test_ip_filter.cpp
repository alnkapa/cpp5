#include "my_ip.h"
#include "my_set.h"
#include "gtest/gtest.h"
#include <iostream>
#include <random>
#include <sstream>

// Функция для генерации случайной строки из целых чисел
MyIp generateRandomNumbers() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 255); // Генерируем числа от 0 до 255
  int num0{};
  int num1{};
  int num2{};
  int num3{};
  for (int i = 0; i < 4; ++i) {
    switch (i) {
    case 0:
      num0 = dis(gen);
      break;
    case 1:
      num1 = dis(gen);
      break;
    case 2:
      num2 = dis(gen);
      break;
    case 3:
      num3 = dis(gen);
      break;
    }
  };
  return MyIp(num0, num1, num2, num3);
}

TEST(read, ReadTest) {
  for (auto i = 0; i < 100; i++) {
    auto ip{generateRandomNumbers()};
    std::ostringstream oss;
    oss << ip << "\t111\t0";
    std::istringstream iss(oss.str());
    auto sst{read(iss)};
    auto num = sst.cbegin();
    EXPECT_EQ((*num).m_num0, ip.m_num0);
    EXPECT_EQ((*num).m_num1, ip.m_num1);
    EXPECT_EQ((*num).m_num2, ip.m_num2);
    EXPECT_EQ((*num).m_num3, ip.m_num3);
  }
};

TEST(read1, ReadTest) {
  for (auto i = 0; i < 100; i++) {
    auto ip{generateRandomNumbers()};
    auto ip1{generateRandomNumbers()};
    ip.m_num0 = 100;
    ip1.m_num0 = 200;
    std::ostringstream oss;
    oss << ip << "\t111\t0"
        << "\n";
    oss << ip1 << "\t434\t23";
    std::istringstream iss(oss.str());
    auto sst{read(iss)};
    for (auto &s : sst) {
      if (s.m_num0 == 100) {
        EXPECT_EQ(s.m_num0, ip.m_num0);
        EXPECT_EQ(s.m_num1, ip.m_num1);
        EXPECT_EQ(s.m_num2, ip.m_num2);
        EXPECT_EQ(s.m_num3, ip.m_num3);
      } else {
        EXPECT_EQ(s.m_num0, ip1.m_num0);
        EXPECT_EQ(s.m_num1, ip1.m_num1);
        EXPECT_EQ(s.m_num2, ip1.m_num2);
        EXPECT_EQ(s.m_num3, ip1.m_num3);
      }
    };
  }
};
