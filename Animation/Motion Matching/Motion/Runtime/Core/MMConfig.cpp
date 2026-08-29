#include "MMConfig.h"

namespace motion {
const ModuleDescriptor &module_mmconfig() {
    static const ModuleDescriptor descriptor{"MMConfig", "Runtime/editor configuration for quality tiers and feature switches."};
    return descriptor;
}
} // namespace motion
