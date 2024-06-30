#include "widget.h"

void WidgetTree::event(const IEvent &in) {
    for (auto it = end(); it != begin(); --it) {
        (*it)->event(in);
    }
}

Dimension WidgetTree::render() {
    Dimension rez{};
    for (auto it = begin(); it != end(); ++it) {
        rez += (*it)->render();
    }
    return rez;
}

void WidgetTree::add(IWidget &&in) {}
