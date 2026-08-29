#pragma once

#include "../Core/MMModule.h"

#include <cstddef>
#include <vector>

namespace motion {

struct PoseFeatureChannel {
    std::size_t offset = 0;
    std::size_t dimension = 0;
};

class PoseFeatureLayout {
public:
    void clear();
    PoseFeatureChannel add_channel(std::size_t dimension);
    std::size_t channel_count() const;
    std::size_t total_dimension() const;
    PoseFeatureChannel channel(std::size_t index) const;

private:
    std::vector<PoseFeatureChannel> channels_;
    std::size_t total_dimension_ = 0;
};

const ModuleDescriptor &module_posefeaturelayout();

} // namespace motion
