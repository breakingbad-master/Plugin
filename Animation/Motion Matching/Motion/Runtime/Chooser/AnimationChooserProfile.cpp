#include "AnimationChooserProfile.h"

namespace motion {
const ModuleDescriptor &module_animationchooserprofile() {
    static const ModuleDescriptor descriptor{"AnimationChooserProfile", "Tunable selection profiles."};
    return descriptor;
}
} // namespace motion
