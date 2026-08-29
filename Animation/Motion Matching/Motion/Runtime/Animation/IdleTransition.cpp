#include "IdleTransition.h"

namespace motion {
const ModuleDescriptor &module_idletransition() {
    static const ModuleDescriptor descriptor{"IdleTransition", "Transitions into and out of idle."};
    return descriptor;
}
} // namespace motion
