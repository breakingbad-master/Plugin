#include "AnimationCurveCompressor.h"

namespace motion {
const ModuleDescriptor &module_animationcurvecompressor() {
    static const ModuleDescriptor descriptor{"AnimationCurveCompressor", "Compresses curve keys for memory."};
    return descriptor;
}
} // namespace motion
