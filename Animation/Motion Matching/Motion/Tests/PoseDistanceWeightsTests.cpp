#include "../Runtime/Pose/PoseDistanceWeights.h"

#include <iostream>
#include <limits>

using namespace motion;

int main() {
    PoseDistanceWeights weights;
    weights.set_feature_weights({2.0f, -1.0f, std::numeric_limits<float>::quiet_NaN()});
    weights.set_bone_weights({0.5f});
    weights.set_contact_weights({3.0f});
    if (weights.feature_weights().size() != 3 || weights.feature(0) != 2.0f ||
        weights.feature(1) != 0.0f || weights.feature(2) != 0.0f || weights.bone(0) != 0.5f ||
        weights.contact(0) != 3.0f || weights.feature(99) != 1.0f || weights.bone(99) != 1.0f) return 1;
    std::cout << "PoseDistanceWeightsTests passed\n";
    return 0;
}
