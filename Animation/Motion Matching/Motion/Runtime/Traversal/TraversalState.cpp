#include "TraversalState.h"

namespace motion {
const ModuleDescriptor &module_traversalstate() {
    static const ModuleDescriptor descriptor{"TraversalState", "Traversal phase state machine."};
    return descriptor;
}
} // namespace motion
