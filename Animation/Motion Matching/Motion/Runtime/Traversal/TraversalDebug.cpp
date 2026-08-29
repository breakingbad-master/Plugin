#include "TraversalDebug.h"

namespace motion {
const ModuleDescriptor &module_traversaldebug() {
    static const ModuleDescriptor descriptor{"TraversalDebug", "Traversal probes and result visualization."};
    return descriptor;
}
} // namespace motion
