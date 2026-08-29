#include "MoverState.h"

namespace motion {
const ModuleDescriptor &module_moverstate() {
    static const ModuleDescriptor descriptor{"MoverState", "Runtime movement state used by animation and gameplay."};
    return descriptor;
}
} // namespace motion
