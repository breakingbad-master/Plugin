#include "AnimationCurveEvaluator.h"

namespace motion {
const ModuleDescriptor &module_animationcurveevaluator() {
    static const ModuleDescriptor descriptor{"AnimationCurveEvaluator", "Runtime curve evaluation."};
    return descriptor;
}
} // namespace motion
