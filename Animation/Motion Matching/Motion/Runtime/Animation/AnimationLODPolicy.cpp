#include "AnimationLODPolicy.h"

namespace motion {
const ModuleDescriptor &module_animationlodpolicy() {
    static const ModuleDescriptor descriptor{"AnimationLODPolicy", "Reduces animation workload based on distance/importance."};
    return descriptor;
}
} // namespace motion
