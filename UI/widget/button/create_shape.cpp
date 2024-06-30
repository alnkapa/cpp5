#include <iostream>

#include "../event/event.h"
#include "button.h"

class CreateShapeEvent : public IEvent {
   public:
    CreateShapeEvent() : IEvent{Type::CreateShape} {};
    void print(std::ostream &out) const override { out << "create shape"; };
};

class CreateShape : public IButton {
   public:
    IEvent click() const override { return CreateShapeEvent(); };
};
