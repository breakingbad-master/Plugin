#include "../Runtime/Pose/PoseDistanceMetric.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    const float weighted = PoseDistanceMetric::squared_distance({1.0f, 2.0f}, {3.0f, 1.0f}, {2.0f, 0.5f});
    if (std::fabs(weighted - 8.5f) > 0.0001f) return 1;
    const float mismatch = PoseDistanceMetric::squared_distance({1.0f}, {1.0f, 2.0f});
    if (std::fabs(mismatch - 4.0f) > 0.0001f) return 1;
    const float invalid = PoseDistanceMetric::squared_distance(
        {std::numeric_limits<float>::quiet_NaN()}, {0.0f});
    if (!std::isinf(invalid)) return 1;
    std::cout << "PoseDistanceMetricTests passed\n";
    return 0;
}
