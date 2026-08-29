#include "PoseDistanceWeights.h"

#include <algorithm>
#include <cmath>
#include <utility>

namespace motion {

void PoseDistanceWeights::sanitize(std::vector<float> &weights) {
    for (float &value : weights) {
        if (!std::isfinite(value) || value < 0.0f) value = 0.0f;
    }
}

void PoseDistanceWeights::set_feature_weights(std::vector<float> weights) {
    sanitize(weights);
    feature_weights_ = std::move(weights);
}
void PoseDistanceWeights::set_bone_weights(std::vector<float> weights) {
    sanitize(weights);
    bone_weights_ = std::move(weights);
}
void PoseDistanceWeights::set_contact_weights(std::vector<float> weights) {
    sanitize(weights);
    contact_weights_ = std::move(weights);
}
const std::vector<float> &PoseDistanceWeights::feature_weights() const { return feature_weights_; }
const std::vector<float> &PoseDistanceWeights::bone_weights() const { return bone_weights_; }
const std::vector<float> &PoseDistanceWeights::contact_weights() const { return contact_weights_; }
float PoseDistanceWeights::feature(std::size_t index) const {
    return index < feature_weights_.size() ? feature_weights_[index] : 1.0f;
}
float PoseDistanceWeights::bone(std::size_t index) const {
    return index < bone_weights_.size() ? bone_weights_[index] : 1.0f;
}
float PoseDistanceWeights::contact(std::size_t index) const {
    return index < contact_weights_.size() ? contact_weights_[index] : 1.0f;
}

const ModuleDescriptor &module_posedistanceweights() {
    static const ModuleDescriptor descriptor{
        "PoseDistanceWeights", "Sanitized per-feature, per-bone, and contact scoring weights."};
    return descriptor;
}

} // namespace motion
