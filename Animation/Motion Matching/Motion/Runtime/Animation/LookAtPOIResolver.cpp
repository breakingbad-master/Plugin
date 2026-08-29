#include "LookAtPOIResolver.h"

namespace motion {
const ModuleDescriptor &module_lookatpoiresolver() {
    static const ModuleDescriptor descriptor{"LookAtPOIResolver", "Selects the best target."};
    return descriptor;
}
} // namespace motion
