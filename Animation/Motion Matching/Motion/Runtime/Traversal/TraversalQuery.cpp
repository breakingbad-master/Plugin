#include "TraversalQuery.h"

namespace motion {
const ModuleDescriptor &module_traversalquery() {
    static const ModuleDescriptor descriptor{"TraversalQuery", "Detects possible traversal opportunities."};
    return descriptor;
}
} // namespace motion
