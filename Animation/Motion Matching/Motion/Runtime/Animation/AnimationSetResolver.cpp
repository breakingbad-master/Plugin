#include "AnimationSetResolver.h"

namespace motion {
const ModuleDescriptor &module_animationsetresolver() {
    static const ModuleDescriptor descriptor{"AnimationSetResolver", "Resolves the correct set from runtime context."};
    return descriptor;
}
} // namespace motion
