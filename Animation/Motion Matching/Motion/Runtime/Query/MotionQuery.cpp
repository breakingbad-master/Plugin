#include "MotionQuery.h"

#include <utility>

namespace motion {

MotionQueryBuilder &MotionQueryBuilder::set_frame(std::uint64_t frame) {
    query_.frame = frame;
    return *this;
}

MotionQueryBuilder &MotionQueryBuilder::set_features(std::vector<float> features) {
    query_.features = std::move(features);
    return *this;
}

MotionQueryBuilder &MotionQueryBuilder::set_trajectory(std::vector<TrajectoryPoint> trajectory) {
    query_.trajectory = std::move(trajectory);
    return *this;
}

MotionQueryBuilder &MotionQueryBuilder::add_tag(std::string tag) {
    query_.tags.push_back(std::move(tag));
    return *this;
}

MotionQueryBuilder &MotionQueryBuilder::set_environment(MotionEnvironmentContext environment) {
    query_.environment = std::move(environment);
    return *this;
}

MotionQuery MotionQueryBuilder::build() const { return query_; }

const ModuleDescriptor &module_motionquery() {
    static const ModuleDescriptor descriptor{
        "MotionQuery", "General query builder for intent, pose, trajectory, contacts, and environment tags."};
    return descriptor;
}

} // namespace motion
