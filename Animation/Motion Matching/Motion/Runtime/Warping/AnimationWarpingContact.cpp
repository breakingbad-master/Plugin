#include "AnimationWarpingContact.h"

namespace motion {
const ModuleDescriptor &module_animationwarpingcontact() {
    static const ModuleDescriptor descriptor{"AnimationWarpingContact", "Contact-driven correction."};
    return descriptor;
}
} // namespace motion
