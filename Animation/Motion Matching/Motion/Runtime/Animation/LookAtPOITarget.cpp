#include "LookAtPOITarget.h"

namespace motion {
const ModuleDescriptor &module_lookatpoitarget() {
    static const ModuleDescriptor descriptor{"LookAtPOITarget", "Represents a point of interest."};
    return descriptor;
}
} // namespace motion
