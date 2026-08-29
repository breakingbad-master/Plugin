#include "LookAtPOISolver.h"

namespace motion {
const ModuleDescriptor &module_lookatpoisolver() {
    static const ModuleDescriptor descriptor{"LookAtPOISolver", "Solves head/eye/body orientation."};
    return descriptor;
}
} // namespace motion
