#include "SmartObjectQuery.h"

namespace motion {
const ModuleDescriptor &module_smartobjectquery() {
    static const ModuleDescriptor descriptor{"SmartObjectQuery", "Finds compatible objects."};
    return descriptor;
}
} // namespace motion
