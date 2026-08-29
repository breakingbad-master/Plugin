#include "MoverExampleController.h"

namespace motion {
const ModuleDescriptor &module_moverexamplecontroller() {
    static const ModuleDescriptor descriptor{"MoverExampleController", "Reference controller demonstrating integration."};
    return descriptor;
}
} // namespace motion
