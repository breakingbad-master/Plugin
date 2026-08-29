#include "TraversalSystem.h"

namespace motion {
const ModuleDescriptor &module_traversalsystem() {
    static const ModuleDescriptor descriptor{"TraversalSystem", "General traversal framework, independent of locomotion."};
    return descriptor;
}
} // namespace motion
