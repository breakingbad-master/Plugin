#include "TraversalRecovery.h"

namespace motion {
const ModuleDescriptor &module_traversalrecovery() {
    static const ModuleDescriptor descriptor{"TraversalRecovery", "Handles failed/interrupted traversal."};
    return descriptor;
}
} // namespace motion
