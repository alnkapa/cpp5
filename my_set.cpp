#include "my_set.h"
#include <iostream>
#include <limits>

// загрузить список ip-адресов в память и отсортировать их в обратном
// лексикографическом порядке.
MySet read(std::istream &in) {
  int num0{};
  int num1{};
  int num2{};
  int num3{};
  auto max = std::numeric_limits<std::streamsize>::max();
  MySet sst{};
  int count{};
  while (!in.fail() || !in.eof()) {
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
      sst.insert(MyIp(num0, num1, num2, num3));
      count = 0;
      break;
    }
  };
  return sst;
}