#include "ClimbTraversal.h"

namespace motion {
const ModuleDescriptor &module_climbtraversal() {
    static const ModuleDescriptor descriptor{"ClimbTraversal", "Climb action logic."};
    return descriptor;
}
} // namespace motion
