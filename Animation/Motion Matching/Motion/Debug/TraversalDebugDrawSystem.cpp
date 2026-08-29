#include "TraversalDebugDrawSystem.h"

namespace motion {
const ModuleDescriptor &module_traversaldebugdrawsystem() {
    static const ModuleDescriptor descriptor{"TraversalDebugDrawSystem", "Traversal probe/result visualization."};
    return descriptor;
}
} // namespace motion
