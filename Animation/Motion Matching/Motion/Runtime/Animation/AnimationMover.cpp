#include "AnimationMover.h"

namespace motion {
const ModuleDescriptor &module_animationmover() {
    static const ModuleDescriptor descriptor{"AnimationMover", "Moves character motion according to animation/root-motion policy."};
    return descriptor;
}
} // namespace motion
