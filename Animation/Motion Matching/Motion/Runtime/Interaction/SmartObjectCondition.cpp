#include "SmartObjectCondition.h"

namespace motion {
const ModuleDescriptor &module_smartobjectcondition() {
    static const ModuleDescriptor descriptor{"SmartObjectCondition", "Context conditions for availability."};
    return descriptor;
}
} // namespace motion
