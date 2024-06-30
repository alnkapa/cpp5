#pragma once
#include <iostream>

enum class Type { No, CreateDocument, ExportDocument, ImportDocument, CreateShape, DeleteShape };

class IEvent {
   public:    
    Type type() const { return m_type; };
    //virtual void print(std::ostream &) const = 0;
    virtual ~IEvent() = default;
    IEvent() = delete;
    IEvent(Type type) : m_type(type){};

   private:
    Type m_type{Type::No};
};
