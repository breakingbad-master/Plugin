#include "TraversalEditor.h"

namespace motion {
const ModuleDescriptor &module_traversaleditor() {
    static const ModuleDescriptor descriptor{"TraversalEditor", "Traversal probe/candidate editor."};
    return descriptor;
}
} // namespace motion
