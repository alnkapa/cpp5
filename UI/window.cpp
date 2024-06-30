#include "window.h"

#include <chrono>
#include <iostream>
#include <thread>

#include "widget/button/create_document.h"

// main proccess loop
void Window::run() {
    auto  d = CreateDocument{};
    while (true) {
        while (!m_events.empty()) {
            const auto &event = m_events.front();
            std::cout << "Processing event: ";
            m_widget.event(event);
            //event.print(std::cout);
            std::cout << std::endl;
            m_events.pop();
        }
        [[maybe_unused]] auto size = m_widget.render();
        // Make something with size
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}