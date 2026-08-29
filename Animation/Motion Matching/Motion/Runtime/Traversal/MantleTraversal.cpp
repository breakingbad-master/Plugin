#include "MantleTraversal.h"

namespace motion {
const ModuleDescriptor &module_mantletraversal() {
    static const ModuleDescriptor descriptor{"MantleTraversal", "Mantle action logic."};
    return descriptor;
}
} // namespace motion
