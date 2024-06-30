#include <iostream>

#include "../event/event.h"
#include "button.h"

class DeleteShapeEvent : public IEvent {
   public:
    DeleteShapeEvent() : IEvent{Type::DeleteShape} {};
    void print(std::ostream &out) const override { out << "delete shape"; };
};

class DeleteShape : public IButton {
   public:
    IEvent click() const override { return DeleteShapeEvent(); };
};
