#include "PoseContinuityScorer.h"

namespace motion {
const ModuleDescriptor &module_posecontinuityscorer() {
    static const ModuleDescriptor descriptor{"PoseContinuityScorer", "Penalizes visually bad transitions."};
    return descriptor;
}
} // namespace motion
