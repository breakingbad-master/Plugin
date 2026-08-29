#include "MotionQueryWeightProfile.h"

#include <cmath>
#include <utility>

namespace motion {

MotionQueryWeightProfile::MotionQueryWeightProfile(std::vector<float> weights) {
    set_weights(std::move(weights));
}

void MotionQueryWeightProfile::set_weights(std::vector<float> weights) {
    for (float &value : weights) {
        if (!std::isfinite(value) || value < 0.0f) value = 0.0f;
    }
    weights_ = std::move(weights);
}

const std::vector<float> &MotionQueryWeightProfile::weights() const { return weights_; }
std::size_t MotionQueryWeightProfile::size() const { return weights_.size(); }
float MotionQueryWeightProfile::weight(std::size_t index) const {
    return index < weights_.size() ? weights_[index] : 1.0f;
}

float MotionQueryWeightProfile::distance(const MotionQueryFeatureVector &a,
                                         const MotionQueryFeatureVector &b) const {
    return a.squared_distance(b, weights_);
}

bool MotionQueryWeightProfile::valid_for(std::size_t dimensions) const {
    return weights_.empty() || weights_.size() == dimensions;
}

const ModuleDescriptor &module_motionqueryweightprofile() {
    static const ModuleDescriptor descriptor{
        "MotionQueryWeightProfile", "Validated per-dimension weights for deterministic feature scoring."};
    return descriptor;
}

} // namespace motion
