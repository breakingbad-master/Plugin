#include "TraversalWarp.h"

namespace motion {
const ModuleDescriptor &module_traversalwarp() {
    static const ModuleDescriptor descriptor{"TraversalWarp", "Corrects animation to geometry."};
    return descriptor;
}
} // namespace motion
