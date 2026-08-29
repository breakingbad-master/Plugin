#include "JumpTraversal.h"

namespace motion {
const ModuleDescriptor &module_jumptraversal() {
    static const ModuleDescriptor descriptor{"JumpTraversal", "Jump traversal logic."};
    return descriptor;
}
} // namespace motion
