#include "AnimationClipSampler.h"

namespace motion {
const ModuleDescriptor &module_animationclipsampler() {
    static const ModuleDescriptor descriptor{"AnimationClipSampler", "Samples arbitrary clips into searchable frames."};
    return descriptor;
}
} // namespace motion
