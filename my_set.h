#pragma once
#include "my_ip.h"
#include <set>

using MySet = std::multiset<MyIp>;
MySet read(std::istream &in);