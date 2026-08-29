#include "AnimationWarpingModifier.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingmodifier() {
    static const ModuleDescriptor descriptor{"AnimationWarpingModifier", "Base modifier for non-locomotion animation warping."};
    return descriptor;
}
} // namespace motion
