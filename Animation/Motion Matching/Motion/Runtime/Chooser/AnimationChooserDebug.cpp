#include "AnimationChooserDebug.h"

namespace motion {
const ModuleDescriptor &module_animationchooserdebug() {
    static const ModuleDescriptor descriptor{"AnimationChooserDebug", "Explains why an animation was selected."};
    return descriptor;
}
} // namespace motion
