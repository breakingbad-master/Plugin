#include "AnimationTagSystem.h"

namespace motion {
const ModuleDescriptor &module_animationtagsystem() {
    static const ModuleDescriptor descriptor{"AnimationTagSystem", "Tags animations by action, stance, context, surface, and gameplay use."};
    return descriptor;
}
} // namespace motion
