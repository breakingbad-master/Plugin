#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <string_view>

namespace motion {

class MotionQueryBuilder {
public:
    MotionQueryBuilder &set_frame(std::uint64_t frame);
    MotionQueryBuilder &set_features(std::vector<float> features);
    MotionQueryBuilder &set_trajectory(std::vector<TrajectoryPoint> trajectory);
    MotionQueryBuilder &add_tag(std::string tag);
    MotionQueryBuilder &set_environment(MotionEnvironmentContext environment);
    MotionQuery build() const;

private:
    MotionQuery query_;
};

const ModuleDescriptor &module_motionquery();

} // namespace motion
