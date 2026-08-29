#include "SmartObjectRelease.h"

namespace motion {
const ModuleDescriptor &module_smartobjectrelease() {
    static const ModuleDescriptor descriptor{"SmartObjectRelease", "Releases a claim safely."};
    return descriptor;
}
} // namespace motion
