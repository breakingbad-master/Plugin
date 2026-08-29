#include "SmartObjectDefinition.h"

namespace motion {
const ModuleDescriptor &module_smartobjectdefinition() {
    static const ModuleDescriptor descriptor{"SmartObjectDefinition", "Defines an object's interaction capabilities."};
    return descriptor;
}
} // namespace motion
