#include "MotionQueryNormalizer.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace motion {

void MotionQueryNormalizer::fit(const std::vector<std::vector<float>> &samples) {
    minimum_.clear();
    maximum_.clear();
    std::size_t dimensions = 0;
    for (const auto &sample : samples) dimensions = std::max(dimensions, sample.size());
    if (dimensions == 0) return;
    minimum_.assign(dimensions, std::numeric_limits<float>::infinity());
    maximum_.assign(dimensions, -std::numeric_limits<float>::infinity());
    for (const auto &sample : samples) {
        for (std::size_t i = 0; i < sample.size(); ++i) {
            minimum_[i] = std::min(minimum_[i], sample[i]);
            maximum_[i] = std::max(maximum_[i], sample[i]);
        }
    }
    for (std::size_t i = 0; i < dimensions; ++i) {
        if (!std::isfinite(minimum_[i])) minimum_[i] = 0.0f;
        if (!std::isfinite(maximum_[i])) maximum_[i] = minimum_[i];
    }
}

MotionQueryFeatureVector MotionQueryNormalizer::normalize(const MotionQueryFeatureVector &value) const {
    MotionQueryFeatureVector normalized = value;
    normalized.normalize(minimum_, maximum_);
    return normalized;
}

const std::vector<float> &MotionQueryNormalizer::minimum() const { return minimum_; }
const std::vector<float> &MotionQueryNormalizer::maximum() const { return maximum_; }
bool MotionQueryNormalizer::fitted() const { return !minimum_.empty() && minimum_.size() == maximum_.size(); }

const ModuleDescriptor &module_motionquerynormalizer() {
    static const ModuleDescriptor descriptor{
        "MotionQueryNormalizer", "Per-dimension min/max fitting with safe clamped feature normalization."};
    return descriptor;
}

} // namespace motion
