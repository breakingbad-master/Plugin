#include "PoseFeatureLayout.h"

namespace motion {

void PoseFeatureLayout::clear() {
    channels_.clear();
    total_dimension_ = 0;
}

PoseFeatureChannel PoseFeatureLayout::add_channel(std::size_t dimension) {
    const PoseFeatureChannel channel{total_dimension_, dimension};
    channels_.push_back(channel);
    total_dimension_ += dimension;
    return channel;
}

std::size_t PoseFeatureLayout::channel_count() const { return channels_.size(); }
std::size_t PoseFeatureLayout::total_dimension() const { return total_dimension_; }
PoseFeatureChannel PoseFeatureLayout::channel(std::size_t index) const {
    return index < channels_.size() ? channels_[index] : PoseFeatureChannel{total_dimension_, 0};
}

const ModuleDescriptor &module_posefeaturelayout() {
    static const ModuleDescriptor descriptor{
        "PoseFeatureLayout", "Deterministic packed pose-channel offsets and total dimensions."};
    return descriptor;
}

} // namespace motion
