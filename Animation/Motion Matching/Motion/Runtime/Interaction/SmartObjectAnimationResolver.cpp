#include "SmartObjectAnimationResolver.h"

namespace motion {
const ModuleDescriptor &module_smartobjectanimationresolver() {
    static const ModuleDescriptor descriptor{"SmartObjectAnimationResolver", "Maps smart-object states to animations."};
    return descriptor;
}
} // namespace motion
