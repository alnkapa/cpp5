#pragma once
#include <iostream>

class IEvent {
   public:
    virtual void print(std::ostream &) const = 0;
};

class Resize_Event : public IEvent {
   public:
    void print(std::ostream &out) const;
};