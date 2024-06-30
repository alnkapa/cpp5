#include <iostream>

#include "../event/event.h"
#include "button.h"

class ExportDocumentEvent : public IEvent {
   public:
    ExportDocumentEvent() : IEvent{Type::ExportDocument} {};
    void print(std::ostream &out) const override { out << "export document"; };    
};

class ExportDocument : public IButton {
   public:
    IEvent click() const override { return ExportDocumentEvent(); };
};
