#include "InteractionDebugDraw.h"

namespace motion {
const ModuleDescriptor &module_interactiondebugdraw() {
    static const ModuleDescriptor descriptor{"InteractionDebugDraw", "Interaction alignment and slot visualization."};
    return descriptor;
}
} // namespace motion
