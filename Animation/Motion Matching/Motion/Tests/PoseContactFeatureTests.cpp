#include "../Runtime/Pose/PoseContactFeature.h"

#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    PoseContactSample grounded;
    grounded.height_above_ground = 0.02f;
    grounded.velocity = {0.05f, 0.0f, 0.0f};
    grounded.confidence = 1.5f;
    PoseContactSample moving;
    moving.height_above_ground = 0.02f;
    moving.velocity = {1.0f, 0.0f, 0.0f};
    moving.confidence = 0.8f;
    const auto values = PoseContactFeature::encode({grounded, moving}, 0.08f, 0.15f);
    if (values.size() != 4 || values[0] != 1.0f || values[1] != 1.0f || values[2] != 0.0f || values[3] != 0.0f) return 1;
    std::cout << "PoseContactFeatureTests passed\n";
    return 0;
}
