#include "TakedownQuery.h"

namespace motion {
const ModuleDescriptor &module_takedownquery() {
    static const ModuleDescriptor descriptor{"TakedownQuery", "Finds valid takedown candidates."};
    return descriptor;
}
} // namespace motion
