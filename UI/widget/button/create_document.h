#pragma once
#include <iostream>

#include "../../event/event.h"
#include "button.h"

class CreateDocumentEvent : public IEvent {
   public:
    CreateDocumentEvent() : IEvent{Type::CreateDocument} {};
    //void print(std::ostream &out) const override { out << "create document"; };
};

class CreateDocument : public IButton {
   public:
    IEvent click() const override { return CreateDocumentEvent(); };
};
