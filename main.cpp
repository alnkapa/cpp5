#include <iostream>

#include "UI/window.h"

int main() {
    auto w{Window{}};
    try {
        w.run();
    } catch (...) {
        std::cerr << "some error" << std::endl;
    }
    return 0;
}