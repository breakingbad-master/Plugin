#include "AnimationWarpingDebug.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingdebug() {
    static const ModuleDescriptor descriptor{"AnimationWarpingDebug", "Debug visualization for animation warping."};
    return descriptor;
}
} // namespace motion
