#include "LookAtPOISystem.h"

namespace motion {
const ModuleDescriptor &module_lookatpoisystem() {
    static const ModuleDescriptor descriptor{"LookAtPOISystem", "Look-at points of interest system."};
    return descriptor;
}
} // namespace motion
