#include "AnimationChooserVariant.h"

namespace motion {
const ModuleDescriptor &module_animationchooservariant() {
    static const ModuleDescriptor descriptor{"AnimationChooserVariant", "Variant selection for repeated actions."};
    return descriptor;
}
} // namespace motion
