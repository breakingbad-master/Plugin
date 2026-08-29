#include "ShoveSystem.h"

namespace motion {
const ModuleDescriptor &module_shovesystem() {
    static const ModuleDescriptor descriptor{"ShoveSystem", "General shove interaction."};
    return descriptor;
}
} // namespace motion
