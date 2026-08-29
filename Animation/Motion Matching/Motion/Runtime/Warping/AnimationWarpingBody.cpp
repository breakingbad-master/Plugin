#include "AnimationWarpingBody.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingbody() {
    static const ModuleDescriptor descriptor{"AnimationWarpingBody", "Body alignment correction."};
    return descriptor;
}
} // namespace motion
