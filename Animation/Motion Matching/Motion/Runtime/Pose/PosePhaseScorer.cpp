#include "PosePhaseScorer.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace motion {

float PosePhaseScorer::score(float query_phase, float candidate_phase, float weight) {
    if (!std::isfinite(query_phase) || !std::isfinite(candidate_phase) || !std::isfinite(weight)) {
        return std::numeric_limits<float>::infinity();
    }
    const float safe_weight = std::max(0.0f, weight);
    float difference = candidate_phase - query_phase;
    difference -= std::floor(difference);
    if (difference > 0.5f) difference -= 1.0f;
    return std::fabs(difference) * safe_weight;
}

const ModuleDescriptor &module_posephasescorer() {
    static const ModuleDescriptor descriptor{
        "PosePhaseScorer", "Wrap-aware weighted cyclic phase continuity penalty."};
    return descriptor;
}

} // namespace motion
