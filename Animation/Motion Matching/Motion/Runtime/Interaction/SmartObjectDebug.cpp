#include "SmartObjectDebug.h"

namespace motion {
const ModuleDescriptor &module_smartobjectdebug() {
    static const ModuleDescriptor descriptor{"SmartObjectDebug", "Visualizes slots, claims, and state."};
    return descriptor;
}
} // namespace motion
