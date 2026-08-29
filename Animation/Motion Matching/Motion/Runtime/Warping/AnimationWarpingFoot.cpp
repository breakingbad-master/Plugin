#include "AnimationWarpingFoot.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingfoot() {
    static const ModuleDescriptor descriptor{"AnimationWarpingFoot", "Foot placement correction."};
    return descriptor;
}
} // namespace motion
