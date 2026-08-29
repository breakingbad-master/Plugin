#include "BenchInteraction.h"

namespace motion {
const ModuleDescriptor &module_benchinteraction() {
    static const ModuleDescriptor descriptor{"BenchInteraction", "Bench sit/stand and contextual interaction example."};
    return descriptor;
}
} // namespace motion
