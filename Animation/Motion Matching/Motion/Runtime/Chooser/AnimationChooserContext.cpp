#include "AnimationChooserContext.h"

namespace motion {
const ModuleDescriptor &module_animationchoosercontext() {
    static const ModuleDescriptor descriptor{"AnimationChooserContext", "Runtime context supplied to chooser rules."};
    return descriptor;
}
} // namespace motion
