#include "AnimationChooserFallback.h"

namespace motion {
const ModuleDescriptor &module_animationchooserfallback() {
    static const ModuleDescriptor descriptor{"AnimationChooserFallback", "Safe fallback when no ideal animation exists."};
    return descriptor;
}
} // namespace motion
