#include "AnimationSet.h"

namespace motion {
const ModuleDescriptor &module_animationset() {
    static const ModuleDescriptor descriptor{"AnimationSet", "Groups related clips for a character or feature."};
    return descriptor;
}
} // namespace motion
