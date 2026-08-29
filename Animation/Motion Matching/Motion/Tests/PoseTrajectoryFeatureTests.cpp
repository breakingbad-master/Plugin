#include "../Runtime/Pose/PoseTrajectoryFeature.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    TrajectoryPoint point;
    point.position = {1.0f, 2.0f, 3.0f};
    point.velocity = {4.0f, 5.0f, 6.0f};
    point.facing_yaw = 0.5f;
    const auto values = PoseTrajectoryFeature::encode({point}, 2.0f, 0.5f, 3.0f);
    if (values.size() != 7 || values[0] != 2.0f || values[2] != 6.0f ||
        values[3] != 2.0f || values[5] != 3.0f || std::fabs(values[6] - 1.5f) > 0.0001f) return 1;
    const auto sanitized = PoseTrajectoryFeature::encode({point}, -1.0f,
        std::numeric_limits<float>::quiet_NaN(), 1.0f);
    if (sanitized[0] != 0.0f || sanitized[3] != 0.0f || sanitized[6] != 0.5f) return 1;
    std::cout << "PoseTrajectoryFeatureTests passed\n";
    return 0;
}
