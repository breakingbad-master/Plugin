#include "CatchTraversal.h"

namespace motion {
const ModuleDescriptor &module_catchtraversal() {
    static const ModuleDescriptor descriptor{"CatchTraversal", "Catch/fall recovery traversal."};
    return descriptor;
}
} // namespace motion
