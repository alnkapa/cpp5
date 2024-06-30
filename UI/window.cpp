#include "window.h"

#include <chrono>
#include <iostream>
#include <thread>


// main proccess loop
void Window::run() {
    while (true) {
        while (!m_events.empty()) {
            const auto &event = m_events.front();
            std::cout << "Processing event: ";
            event.print(std::cout);
            std::cout << std::endl;
            m_events.pop();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}