#include "TakedownWarp.h"

namespace motion {
const ModuleDescriptor &module_takedownwarp() {
    static const ModuleDescriptor descriptor{"TakedownWarp", "Warps takedown animation to target."};
    return descriptor;
}
} // namespace motion
