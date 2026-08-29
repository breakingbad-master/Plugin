#include "../Runtime/Pose/PoseBoneFeature.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    PoseBoneTransform first;
    first.position = {1.0f, 2.0f, 3.0f};
    first.forward = {0.0f, 0.0f, 2.0f};
    first.weight = 2.0f;
    PoseBoneTransform second;
    second.forward = {0.0f, 0.0f, 0.0f};
    second.weight = std::numeric_limits<float>::quiet_NaN();
    const auto values = PoseBoneFeature::encode({first, second});
    if (values.size() != 12) return 1;
    if (std::fabs(values[0] - 2.0f) > 0.0001f || std::fabs(values[5] - 2.0f) > 0.0001f) return 1;
    for (std::size_t i = 6; i < values.size(); ++i) if (values[i] != 0.0f) return 1;
    std::cout << "PoseBoneFeatureTests passed\n";
    return 0;
}
