#include "TakedownAlignment.h"

namespace motion {
const ModuleDescriptor &module_takedownalignment() {
    static const ModuleDescriptor descriptor{"TakedownAlignment", "Aligns attacker and victim."};
    return descriptor;
}
} // namespace motion
