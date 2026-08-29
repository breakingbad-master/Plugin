#include "AnimationChooserHistory.h"

namespace motion {
const ModuleDescriptor &module_animationchooserhistory() {
    static const ModuleDescriptor descriptor{"AnimationChooserHistory", "Tracks recent selections."};
    return descriptor;
}
} // namespace motion
