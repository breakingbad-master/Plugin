#include "MotionWarpingTranslation.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingtranslation() {
    static const ModuleDescriptor descriptor{"MotionWarpingTranslation", "Translation correction."};
    return descriptor;
}
} // namespace motion
