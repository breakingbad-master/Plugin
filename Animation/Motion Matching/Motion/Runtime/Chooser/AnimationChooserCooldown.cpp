#include "AnimationChooserCooldown.h"

namespace motion {
const ModuleDescriptor &module_animationchoosercooldown() {
    static const ModuleDescriptor descriptor{"AnimationChooserCooldown", "Prevents undesirable immediate repetition."};
    return descriptor;
}
} // namespace motion
