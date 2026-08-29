#include "SmartObjectBehavior.h"

namespace motion {
const ModuleDescriptor &module_smartobjectbehavior() {
    static const ModuleDescriptor descriptor{"SmartObjectBehavior", "Behavior selected after claiming."};
    return descriptor;
}
} // namespace motion
