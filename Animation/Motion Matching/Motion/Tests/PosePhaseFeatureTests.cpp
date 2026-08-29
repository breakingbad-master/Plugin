#include "../Runtime/Pose/PosePhaseFeature.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    if (std::fabs(PosePhaseFeature::normalize(-0.25f) - 0.75f) > 0.0001f) return 1;
    if (std::fabs(PosePhaseFeature::normalize(2.25f) - 0.25f) > 0.0001f) return 1;
    if (PosePhaseFeature::normalize(std::numeric_limits<float>::quiet_NaN()) != 0.0f) return 1;
    if (std::fabs(PosePhaseFeature::delta(0.95f, 0.05f) - 0.1f) > 0.0001f) return 1;
    const auto encoded = PosePhaseFeature::encode(1.0f);
    if (std::fabs(encoded[0] - 1.0f) > 0.0001f || std::fabs(encoded[1]) > 0.0001f) return 1;
    std::cout << "PosePhaseFeatureTests passed\n";
    return 0;
}
