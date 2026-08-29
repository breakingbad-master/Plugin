#include "../Runtime/Pose/PoseAngularVelocityFeature.h"

#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    constexpr float pi = 3.14159265358979323846f;
    const std::vector<PoseEulerAngles> previous{{0.0f, pi - 0.1f, 0.0f}};
    const std::vector<PoseEulerAngles> current{{0.0f, -pi + 0.1f, 0.2f}};
    const auto velocities = PoseAngularVelocityFeature::derive(previous, current, 0.1f);
    if (velocities.size() != 1 || std::fabs(velocities[0].yaw - 2.0f) > 0.0001f ||
        std::fabs(velocities[0].roll - 2.0f) > 0.0001f) return 1;
    const auto flattened = PoseAngularVelocityFeature::flatten(velocities, 0.5f);
    if (flattened.size() != 3 || std::fabs(flattened[1] - 1.0f) > 0.0001f) return 1;
    std::cout << "PoseAngularVelocityFeatureTests passed\n";
    return 0;
}
