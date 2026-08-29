#include "SmartObjectClaim.h"

namespace motion {
const ModuleDescriptor &module_smartobjectclaim() {
    static const ModuleDescriptor descriptor{"SmartObjectClaim", "Reserves an object slot."};
    return descriptor;
}
} // namespace motion
