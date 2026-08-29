#include "TraversalCandidate.h"

namespace motion {
const ModuleDescriptor &module_traversalcandidate() {
    static const ModuleDescriptor descriptor{"TraversalCandidate", "Represents one traversal solution."};
    return descriptor;
}
} // namespace motion
