#include "AnimationChooser.h"

namespace motion {
const ModuleDescriptor &module_animationchooser() {
    static const ModuleDescriptor descriptor{"AnimationChooser", "General-purpose animation selection layer for any action."};
    return descriptor;
}
} // namespace motion
