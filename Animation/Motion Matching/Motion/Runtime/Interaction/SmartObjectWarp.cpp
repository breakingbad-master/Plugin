#include "SmartObjectWarp.h"

namespace motion {
const ModuleDescriptor &module_smartobjectwarp() {
    static const ModuleDescriptor descriptor{"SmartObjectWarp", "Aligns characters to object slots."};
    return descriptor;
}
} // namespace motion
