#include "../Runtime/Pose/PoseContinuityScorer.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    const float score = PoseContinuityScorer::score({1.0f, 2.0f}, {3.0f, 1.0f}, 2.0f);
    if (std::fabs(score - 6.0f) > 0.0001f) return 1;
    const float mismatch = PoseContinuityScorer::score({1.0f}, {1.0f, 2.0f});
    if (std::fabs(mismatch - 2.0f) > 0.0001f) return 1;
    const float invalid = PoseContinuityScorer::score({0.0f}, {0.0f},
        std::numeric_limits<float>::quiet_NaN());
    if (!std::isinf(invalid)) return 1;
    std::cout << "PoseContinuityScorerTests passed\n";
    return 0;
}
