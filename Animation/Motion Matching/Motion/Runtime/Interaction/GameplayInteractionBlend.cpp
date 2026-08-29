#include "GameplayInteractionBlend.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionblend() {
    static const ModuleDescriptor descriptor{"GameplayInteractionBlend", "Blends into/out of interactions."};
    return descriptor;
}
} // namespace motion
