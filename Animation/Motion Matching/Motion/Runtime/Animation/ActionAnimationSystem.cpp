#include "ActionAnimationSystem.h"

namespace motion {
const ModuleDescriptor &module_actionanimationsystem() {
    static const ModuleDescriptor descriptor{"ActionAnimationSystem", "Generic action animation orchestration."};
    return descriptor;
}
} // namespace motion
