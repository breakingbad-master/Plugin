#include "AnimationVariantResolver.h"

namespace motion {
const ModuleDescriptor &module_animationvariantresolver() {
    static const ModuleDescriptor descriptor{"AnimationVariantResolver", "Selects among multiple variants instead of assuming one clip."};
    return descriptor;
}
} // namespace motion
