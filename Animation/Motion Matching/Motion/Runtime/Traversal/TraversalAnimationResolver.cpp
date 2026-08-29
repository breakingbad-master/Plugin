#include "TraversalAnimationResolver.h"

namespace motion {
const ModuleDescriptor &module_traversalanimationresolver() {
    static const ModuleDescriptor descriptor{"TraversalAnimationResolver", "Selects traversal variants."};
    return descriptor;
}
} // namespace motion
