#include "TakedownTargeting.h"

namespace motion {
const ModuleDescriptor &module_takedowntargeting() {
    static const ModuleDescriptor descriptor{"TakedownTargeting", "Determines attacker/target alignment."};
    return descriptor;
}
} // namespace motion
