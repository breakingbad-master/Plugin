#include "SmartObjectSystem.h"

namespace motion {
const ModuleDescriptor &module_smartobjectsystem() {
    static const ModuleDescriptor descriptor{"SmartObjectSystem", "Registry and runtime manager for contextual world interactions."};
    return descriptor;
}
} // namespace motion
