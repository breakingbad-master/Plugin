#include "TakedownSystem.h"

namespace motion {
const ModuleDescriptor &module_takedownsystem() {
    static const ModuleDescriptor descriptor{"TakedownSystem", "Specialized takedown layer using the general interaction framework."};
    return descriptor;
}
} // namespace motion
