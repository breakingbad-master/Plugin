#include "../Runtime/Pose/PoseRootFeature.h"

#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    PoseRootSample sample;
    sample.position = {1.0f, 2.0f, 3.0f};
    sample.velocity = {4.0f, 5.0f, 6.0f};
    sample.facing_yaw = 0.5f;
    sample.weight = 2.0f;
    const auto values = PoseRootFeature::encode({sample});
    if (values.size() != 7 || values[0] != 2.0f || values[2] != 6.0f ||
        values[3] != 8.0f || values[5] != 12.0f || std::fabs(values[6] - 1.0f) > 0.0001f) return 1;
    std::cout << "PoseRootFeatureTests passed\n";
    return 0;
}
