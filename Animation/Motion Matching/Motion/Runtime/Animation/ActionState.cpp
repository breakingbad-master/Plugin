#include "ActionState.h"

namespace motion {
const ModuleDescriptor &module_actionstate() {
    static const ModuleDescriptor descriptor{"ActionState", "Generic action state tracking."};
    return descriptor;
}
} // namespace motion
