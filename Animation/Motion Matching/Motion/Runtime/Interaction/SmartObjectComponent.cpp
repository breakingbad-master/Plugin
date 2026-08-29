#include "SmartObjectComponent.h"

namespace motion {
const ModuleDescriptor &module_smartobjectcomponent() {
    static const ModuleDescriptor descriptor{"SmartObjectComponent", "Runtime component attached to an object."};
    return descriptor;
}
} // namespace motion
