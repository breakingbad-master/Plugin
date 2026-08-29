#include "AnimationWarpingBlend.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingblend() {
    static const ModuleDescriptor descriptor{"AnimationWarpingBlend", "Blends multiple warping influences."};
    return descriptor;
}
} // namespace motion
