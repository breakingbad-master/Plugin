#include "../Runtime/Pose/PosePhaseScorer.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    if (std::fabs(PosePhaseScorer::score(0.95f, 0.05f, 2.0f) - 0.2f) > 0.0001f) return 1;
    if (std::fabs(PosePhaseScorer::score(0.2f, 0.2f)) > 0.0001f) return 1;
    const float invalid = PosePhaseScorer::score(0.0f,
        std::numeric_limits<float>::quiet_NaN());
    if (!std::isinf(invalid)) return 1;
    std::cout << "PosePhaseScorerTests passed\n";
    return 0;
}
