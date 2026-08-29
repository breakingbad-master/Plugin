#include "SmartObjectEditor.h"

namespace motion {
const ModuleDescriptor &module_smartobjecteditor() {
    static const ModuleDescriptor descriptor{"SmartObjectEditor", "Smart object slot/interaction editor."};
    return descriptor;
}
} // namespace motion
