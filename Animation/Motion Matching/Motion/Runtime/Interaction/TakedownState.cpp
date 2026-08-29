#include "TakedownState.h"

namespace motion {
const ModuleDescriptor &module_takedownstate() {
    static const ModuleDescriptor descriptor{"TakedownState", "Tracks takedown phases."};
    return descriptor;
}
} // namespace motion
