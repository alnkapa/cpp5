#include <iostream>
#include <sstream>
#include <string>

void read() {
  auto find_point = [](const char c) -> bool {
    if (c == '.') {
      return true;
    } else {
      return false;
    }
  };
  std::string::const_iterator old;
  int num;
  while (!std::cin.eof()) {
    std::string in;
    std::getline(std::cin, in);
    for (auto it = in.cbegin(), old = in.cbegin(); it != in.cend(); it++) {
      if (*it == '.' || *it == '\t') {
        std::istringstream(std::string(old, it)) >> num;
        std::cout << (int)(u_char)num << " " << std::string(old, it) << " ";
        old = it + 1;
      }
      if (*it == '\t') {
        break;
      }
    }
    std::cout << "\n";
  }
}

/*
Если  интересно мое мнение. Я бы купил книгу. В каком виде, наверное было бы
удобно для эллектроной читалки.

*/

int main() {
  read();
  return 0;
}