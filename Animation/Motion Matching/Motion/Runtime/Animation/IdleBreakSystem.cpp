#include "IdleBreakSystem.h"

namespace motion {
const ModuleDescriptor &module_idlebreaksystem() {
    static const ModuleDescriptor descriptor{"IdleBreakSystem", "Breaks idle with contextual micro-actions."};
    return descriptor;
}
} // namespace motion
