#include "LookAtPOIBlend.h"

namespace motion {
const ModuleDescriptor &module_lookatpoiblend() {
    static const ModuleDescriptor descriptor{"LookAtPOIBlend", "Blends look-at influence."};
    return descriptor;
}
} // namespace motion
