#include "AnimationCurveNormalizer.h"

namespace motion {
const ModuleDescriptor &module_animationcurvenormalizer() {
    static const ModuleDescriptor descriptor{"AnimationCurveNormalizer", "Normalizes curve values."};
    return descriptor;
}
} // namespace motion
