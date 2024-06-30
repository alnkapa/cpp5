#pragma once
#include <iostream>

#include "../event/event.h"
#include "dimension/dimension.h"

class IWidget {
   public:
    virtual Dimension render() = 0;
    virtual void event(const IEvent&) = 0;
    virtual ~IWidget() = default;
};

class WidgetTree : public IWidget {
   public:
    class Iterator {
       public:
        Iterator(WidgetTree* tree) : m_tree(tree) {}
        WidgetTree* operator*() { return m_tree; }
        Iterator& operator++() { return *this; }
        Iterator& operator--() { return *this; }
        bool operator!=(const Iterator& other) const { return m_tree != other.m_tree; }

       private:
        WidgetTree* m_tree;
    };
    Iterator begin() { return Iterator(this); }
    Iterator end() { return Iterator(nullptr); }
    void event(const IEvent&) override;
    Dimension render() override;
    void add(IWidget&&);
};
