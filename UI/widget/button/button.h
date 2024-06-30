#include "../../event/event.h"
#include "../../widget/widget.h"

class IButton : public IWidget {
   public:
    virtual ~IButton() = default;
    virtual IEvent click() const = 0;
};

