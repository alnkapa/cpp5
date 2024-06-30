#include <iostream>

#include "../event/event.h"
#include "button.h"

class ImportDocumentEvent : public IEvent {
   public:
    ImportDocumentEvent() : IEvent{Type::ImportDocument} {};
    void print(std::ostream &out) const override { out << "import document"; };
};

class ImportDocument : public IButton {
   public:
    IEvent click() const override { return ImportDocumentEvent(); };
};
