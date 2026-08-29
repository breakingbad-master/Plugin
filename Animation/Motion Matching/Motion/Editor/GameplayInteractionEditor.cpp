#include "GameplayInteractionEditor.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractioneditor() {
    static const ModuleDescriptor descriptor{"GameplayInteractionEditor", "Interaction authoring and debugging."};
    return descriptor;
}
} // namespace motion
