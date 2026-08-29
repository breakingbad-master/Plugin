#include "PoseContactScorer.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace motion {

float PoseContactScorer::score(const std::vector<float> &query, const std::vector<float> &candidate,
                               float state_weight, float confidence_weight) {
    const float safe_state = std::isfinite(state_weight) ? std::max(0.0f, state_weight) : 0.0f;
    const float safe_confidence = std::isfinite(confidence_weight) ? std::max(0.0f, confidence_weight) : 0.0f;
    const std::size_t dimensions = std::max(query.size(), candidate.size());
    float total = 0.0f;
    for (std::size_t i = 0; i < dimensions; ++i) {
        const float q = i < query.size() ? query[i] : 0.0f;
        const float c = i < candidate.size() ? candidate[i] : 0.0f;
        if (!std::isfinite(q) || !std::isfinite(c)) return std::numeric_limits<float>::infinity();
        const float weight = (i % 2 == 0) ? safe_state : safe_confidence;
        total += std::fabs(q - c) * weight;
    }
    return total;
}

const ModuleDescriptor &module_posecontactscorer() {
    static const ModuleDescriptor descriptor{
        "PoseContactScorer", "Pair-aware contact state and confidence mismatch scoring."};
    return descriptor;
}

} // namespace motion
