#include "AnimationChooserRule.h"

namespace motion {
const ModuleDescriptor &module_animationchooserrule() {
    static const ModuleDescriptor descriptor{"AnimationChooserRule", "Rule describing a valid selection condition."};
    return descriptor;
}
} // namespace motion
