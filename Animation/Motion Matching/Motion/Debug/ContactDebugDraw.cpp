#include "ContactDebugDraw.h"

namespace motion {
const ModuleDescriptor &module_contactdebugdraw() {
    static const ModuleDescriptor descriptor{"ContactDebugDraw", "Contact points and phases."};
    return descriptor;
}
} // namespace motion
