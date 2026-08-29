#include "../Runtime/Pose/PoseContactScorer.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    const float score = PoseContactScorer::score({1.0f, 0.5f, 0.0f, 1.0f},
                                                  {0.0f, 0.0f, 1.0f, 0.5f}, 2.0f, 3.0f);
    if (std::fabs(score - 7.0f) > 0.0001f) return 1;
    const float invalid = PoseContactScorer::score(
        {std::numeric_limits<float>::quiet_NaN()}, {0.0f});
    if (!std::isinf(invalid)) return 1;
    std::cout << "PoseContactScorerTests passed\n";
    return 0;
}
