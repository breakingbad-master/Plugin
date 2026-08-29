#include "MMDeterminism.h"

namespace motion {
const ModuleDescriptor &module_mmdeterminism() {
    static const ModuleDescriptor descriptor{"MMDeterminism", "Deterministic evaluation support for reproducible tests and networking."};
    return descriptor;
}
} // namespace motion
