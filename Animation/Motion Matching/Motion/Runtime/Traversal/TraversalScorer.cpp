#include "TraversalScorer.h"

namespace motion {
const ModuleDescriptor &module_traversalscorer() {
    static const ModuleDescriptor descriptor{"TraversalScorer", "Ranks traversal candidates."};
    return descriptor;
}
} // namespace motion
