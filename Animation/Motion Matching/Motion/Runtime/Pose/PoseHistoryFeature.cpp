#include "PoseHistoryFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

PoseHistoryFeature::PoseHistoryFeature(std::size_t capacity) : capacity_(capacity) {}

void PoseHistoryFeature::reset() { history_.clear(); }

void PoseHistoryFeature::push(std::vector<float> pose) {
    if (capacity_ == 0) return;
    history_.insert(history_.begin(), std::move(pose));
    if (history_.size() > capacity_) history_.resize(capacity_);
}

std::vector<float> PoseHistoryFeature::flatten(float decay) const {
    const float safe_decay = std::isfinite(decay) ? std::clamp(decay, 0.0f, 1.0f) : 1.0f;
    std::size_t dimensions = 0;
    for (const auto &pose : history_) dimensions = std::max(dimensions, pose.size());
    std::vector<float> flattened;
    flattened.reserve(history_.size() * dimensions);
    float scale = 1.0f;
    for (const auto &pose : history_) {
        for (std::size_t i = 0; i < dimensions; ++i) {
            flattened.push_back(i < pose.size() ? pose[i] * scale : 0.0f);
        }
        scale *= safe_decay;
    }
    return flattened;
}

std::size_t PoseHistoryFeature::size() const { return history_.size(); }
std::size_t PoseHistoryFeature::capacity() const { return capacity_; }

const ModuleDescriptor &module_posehistoryfeature() {
    static const ModuleDescriptor descriptor{
        "PoseHistoryFeature", "Bounded newest-first pose history with validated temporal decay."};
    return descriptor;
}

} // namespace motion
