#include "../Runtime/Pose/PoseHistoryFeature.h"

#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    PoseHistoryFeature history(2);
    history.push({1.0f, 2.0f});
    history.push({3.0f, 4.0f});
    history.push({5.0f, 6.0f});
    if (history.size() != 2 || history.capacity() != 2) return 1;
    const auto flattened = history.flatten(0.5f);
    if (flattened.size() != 4 || flattened[0] != 5.0f || flattened[1] != 6.0f ||
        std::fabs(flattened[2] - 1.5f) > 0.0001f || std::fabs(flattened[3] - 2.0f) > 0.0001f) return 1;
    history.reset();
    if (history.size() != 0 || !history.flatten().empty()) return 1;
    std::cout << "PoseHistoryFeatureTests passed\n";
    return 0;
}
