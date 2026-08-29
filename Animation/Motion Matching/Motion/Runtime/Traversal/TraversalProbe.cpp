#include "TraversalProbe.h"

namespace motion {
const ModuleDescriptor &module_traversalprobe() {
    static const ModuleDescriptor descriptor{"TraversalProbe", "Performs geometry probes for traversal."};
    return descriptor;
}
} // namespace motion
