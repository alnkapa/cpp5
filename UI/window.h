#pragma once
#include <queue>

#include "event/event.h"
#include "widget/widget.h"

class IWindow {
   public:
    virtual void run() = 0;
};

class Window : public IWindow {
   private:
    std::queue<IEvent> m_events{};
    WidgetTree m_widget{};

   public:
    void run() override;
};