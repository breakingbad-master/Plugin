#include "../Runtime/Pose/PoseAccelerationFeature.h"

#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    const std::vector<Vec3> previous{{0.0f, 0.0f, 0.0f}};
    const std::vector<Vec3> current{{2.0f, 4.0f, 6.0f}, {9.0f, 9.0f, 9.0f}};
    const auto accelerations = PoseAccelerationFeature::derive(previous, current, 0.5f);
    if (accelerations.size() != 1 || accelerations[0].x != 4.0f || accelerations[0].y != 8.0f || accelerations[0].z != 12.0f) return 1;
    const auto flattened = PoseAccelerationFeature::flatten(accelerations, 0.5f);
    if (flattened.size() != 3 || flattened[0] != 2.0f || flattened[2] != 6.0f) return 1;
    const auto invalid = PoseAccelerationFeature::derive(previous, current, 0.0f);
    if (invalid.size() != 1 || invalid[0].length_squared() != 0.0f) return 1;
    std::cout << "PoseAccelerationFeatureTests passed\n";
    return 0;
}
