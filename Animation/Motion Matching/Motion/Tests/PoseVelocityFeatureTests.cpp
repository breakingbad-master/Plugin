#include "../Runtime/Pose/PoseVelocityFeature.h"

#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    const std::vector<Vec3> previous{{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}};
    const std::vector<Vec3> current{{1.0f, 0.0f, 0.0f}, {1.0f, 2.0f, 0.0f}, {9.0f, 9.0f, 9.0f}};
    const auto velocities = PoseVelocityFeature::derive(previous, current, 0.5f);
    if (velocities.size() != 2 || std::fabs(velocities[0].x - 2.0f) > 0.0001f ||
        std::fabs(velocities[1].y - 4.0f) > 0.0001f) return 1;
    const auto flattened = PoseVelocityFeature::flatten(velocities, 0.5f);
    if (flattened.size() != 6 || std::fabs(flattened[0] - 1.0f) > 0.0001f ||
        std::fabs(flattened[4] - 2.0f) > 0.0001f) return 1;
    const auto invalid = PoseVelocityFeature::derive(previous, current, 0.0f);
    if (invalid.size() != 2 || invalid[0].length_squared() != 0.0f) return 1;
    std::cout << "PoseVelocityFeatureTests passed\n";
    return 0;
}
