#include "TrajectoryPredictor.h"

namespace motion {
const ModuleDescriptor &module_trajectorypredictor() {
    static const ModuleDescriptor descriptor{"TrajectoryPredictor", "Predicts intended movement from input and gameplay state."};
    return descriptor;
}
} // namespace motion
