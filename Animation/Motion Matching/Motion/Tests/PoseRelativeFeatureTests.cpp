#include "../Runtime/Pose/PoseRelativeFeature.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    PoseRelativePair pair;
    pair.source = {1.0f, 2.0f, 3.0f};
    pair.target = {3.0f, 6.0f, 5.0f};
    pair.weight = 0.5f;
    PoseRelativePair zero_weight;
    zero_weight.source = {9.0f, 9.0f, 9.0f};
    zero_weight.target = {10.0f, 10.0f, 10.0f};
    zero_weight.weight = std::numeric_limits<float>::quiet_NaN();
    const auto encoded = PoseRelativeFeature::encode({pair, zero_weight});
    if (encoded.size() != 6 || std::fabs(encoded[0] - 1.0f) > 0.0001f ||
        std::fabs(encoded[1] - 2.0f) > 0.0001f || std::fabs(encoded[2] - 1.0f) > 0.0001f) return 1;
    for (std::size_t i = 3; i < encoded.size(); ++i) if (encoded[i] != 0.0f) return 1;
    std::cout << "PoseRelativeFeatureTests passed\n";
    return 0;
}
