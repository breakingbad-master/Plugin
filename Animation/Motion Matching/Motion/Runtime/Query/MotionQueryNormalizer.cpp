#include "MotionQueryNormalizer.h"

namespace motion {
const ModuleDescriptor &module_motionquerynormalizer() {
    static const ModuleDescriptor descriptor{"MotionQueryNormalizer", "Normalizes feature ranges before distance scoring."};
    return descriptor;
}
} // namespace motion
