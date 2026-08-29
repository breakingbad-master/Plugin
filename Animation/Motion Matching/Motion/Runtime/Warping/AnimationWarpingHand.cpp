#include "AnimationWarpingHand.h"

namespace motion {
const ModuleDescriptor &module_animationwarpinghand() {
    static const ModuleDescriptor descriptor{"AnimationWarpingHand", "Hand placement correction."};
    return descriptor;
}
} // namespace motion
