#include "AnimationWarpingProfile.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingprofile() {
    static const ModuleDescriptor descriptor{"AnimationWarpingProfile", "Reusable warp configuration."};
    return descriptor;
}
} // namespace motion
