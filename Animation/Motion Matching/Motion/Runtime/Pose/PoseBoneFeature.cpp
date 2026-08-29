#include "PoseBoneFeature.h"

namespace motion {
const ModuleDescriptor &module_posebonefeature() {
    static const ModuleDescriptor descriptor{"PoseBoneFeature", "Bone-position/orientation feature."};
    return descriptor;
}
} // namespace motion
