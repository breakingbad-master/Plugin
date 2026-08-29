#include "AnimationChooserScore.h"

namespace motion {
const ModuleDescriptor &module_animationchooserscore() {
    static const ModuleDescriptor descriptor{"AnimationChooserScore", "Scores candidate animations."};
    return descriptor;
}
} // namespace motion
