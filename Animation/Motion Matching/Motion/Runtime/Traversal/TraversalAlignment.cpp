#include "TraversalAlignment.h"

namespace motion {
const ModuleDescriptor &module_traversalalignment() {
    static const ModuleDescriptor descriptor{"TraversalAlignment", "Aligns character before traversal."};
    return descriptor;
}
} // namespace motion
