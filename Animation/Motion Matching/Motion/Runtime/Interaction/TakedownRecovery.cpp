#include "TakedownRecovery.h"

namespace motion {
const ModuleDescriptor &module_takedownrecovery() {
    static const ModuleDescriptor descriptor{"TakedownRecovery", "Returns both characters to valid states."};
    return descriptor;
}
} // namespace motion
