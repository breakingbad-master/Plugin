#include "MMRuntimeContext.h"

namespace motion {
const ModuleDescriptor &module_mmruntimecontext() {
    static const ModuleDescriptor descriptor{"MMRuntimeContext", "Per-frame context shared by search, scoring, pose, trajectory, and playback."};
    return descriptor;
}
} // namespace motion
