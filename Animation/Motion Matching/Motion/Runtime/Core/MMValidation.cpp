#include "MMValidation.h"

namespace motion {
const ModuleDescriptor &module_mmvalidation() {
    static const ModuleDescriptor descriptor{"MMValidation", "Runtime assertions and validation for malformed animation/query data."};
    return descriptor;
}
} // namespace motion
