#include "PoseDistanceMetric.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace motion {

float PoseDistanceMetric::squared_distance(const std::vector<float> &query,
                                           const std::vector<float> &candidate,
                                           const std::vector<float> &weights) {
    const std::size_t dimensions = std::max(query.size(), candidate.size());
    float total = 0.0f;
    for (std::size_t i = 0; i < dimensions; ++i) {
        const float q = i < query.size() ? query[i] : 0.0f;
        const float c = i < candidate.size() ? candidate[i] : 0.0f;
        if (!std::isfinite(q) || !std::isfinite(c)) return std::numeric_limits<float>::infinity();
        const float weight = i < weights.size() && std::isfinite(weights[i])
            ? std::max(0.0f, weights[i]) : 1.0f;
        const float difference = q - c;
        total += difference * difference * weight;
    }
    return total;
}

const ModuleDescriptor &module_posedistancemetric() {
    static const ModuleDescriptor descriptor{
        "PoseDistanceMetric", "Dimension-safe finite weighted squared-error pose distance."};
    return descriptor;
}

} // namespace motion
