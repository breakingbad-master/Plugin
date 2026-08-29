#include "JumpTakeoff.h"

namespace motion {
const ModuleDescriptor &module_jumptakeoff() {
    static const ModuleDescriptor descriptor{"JumpTakeoff", "Jump-off/takeoff phase handling."};
    return descriptor;
}
} // namespace motion
