#include "ChooserEditor.h"

namespace motion {
const ModuleDescriptor &module_choosereditor() {
    static const ModuleDescriptor descriptor{"ChooserEditor", "Chooser rule/profile editor."};
    return descriptor;
}
} // namespace motion
