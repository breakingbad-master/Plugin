#include "ChooserDebugDraw.h"

namespace motion {
const ModuleDescriptor &module_chooserdebugdraw() {
    static const ModuleDescriptor descriptor{"ChooserDebugDraw", "Candidate and decision visualization."};
    return descriptor;
}
} // namespace motion
