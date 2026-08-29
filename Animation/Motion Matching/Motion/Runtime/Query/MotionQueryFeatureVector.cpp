#include "MotionQueryFeatureVector.h"

#include <algorithm>
#include <limits>
#include <utility>

namespace motion {

MotionQueryFeatureVector::MotionQueryFeatureVector(std::vector<float> values) : values_(std::move(values)) {}
const std::vector<float> &MotionQueryFeatureVector::values() const { return values_; }
std::size_t MotionQueryFeatureVector::size() const { return values_.size(); }
float MotionQueryFeatureVector::at(std::size_t index) const {
    return index < values_.size() ? values_[index] : 0.0f;
}

void MotionQueryFeatureVector::normalize(const std::vector<float> &minimum,
                                         const std::vector<float> &maximum) {
    const std::size_t count = std::min(values_.size(), std::min(minimum.size(), maximum.size()));
    for (std::size_t i = 0; i < count; ++i) {
        const float range = maximum[i] - minimum[i];
        values_[i] = range > std::numeric_limits<float>::epsilon()
            ? std::clamp((values_[i] - minimum[i]) / range, 0.0f, 1.0f)
            : 0.0f;
    }
}

float MotionQueryFeatureVector::squared_distance(const MotionQueryFeatureVector &other,
                                                  const std::vector<float> &weights) const {
    if (values_.size() != other.values_.size()) return std::numeric_limits<float>::infinity();
    float total = 0.0f;
    for (std::size_t i = 0; i < values_.size(); ++i) {
        const float weight = i < weights.size() ? std::max(0.0f, weights[i]) : 1.0f;
        const float delta = values_[i] - other.values_[i];
        total += delta * delta * weight;
    }
    return total;
}

const ModuleDescriptor &module_motionqueryfeaturevector() {
    static const ModuleDescriptor descriptor{
        "MotionQueryFeatureVector", "Packed normalized numeric vector with weighted distance scoring."};
    return descriptor;
}

} // namespace motion
