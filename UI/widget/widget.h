#pragma once
#include <iostream>

#include "dimension/dimension.h"

class IWidget {
   public:
    virtual Dimension render() = 0;
};

class WidgetTree : public IWidget {
   public:
    Dimension render() override;
};
