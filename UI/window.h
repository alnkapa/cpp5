#pragma once
#include <queue>

#include "event/event.h"
#include "widget/widget.h"

class Window {
   private:
    std::queue<IEvent> m_events{};
    WidgetTree m_widget{};

   public:
    void run();
};