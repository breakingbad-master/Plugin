#include "AnimationWarpingSystem.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingsystem() {
    static const ModuleDescriptor descriptor{"AnimationWarpingSystem", "General animation-space deformation/adjustment system."};
    return descriptor;
}
} // namespace motion
