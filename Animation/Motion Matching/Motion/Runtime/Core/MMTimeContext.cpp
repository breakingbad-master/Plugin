#include "MMTimeContext.h"

namespace motion {
const ModuleDescriptor &module_mmtimecontext() {
    static const ModuleDescriptor descriptor{"MMTimeContext", "Normalized animation and simulation time utilities."};
    return descriptor;
}
} // namespace motion
