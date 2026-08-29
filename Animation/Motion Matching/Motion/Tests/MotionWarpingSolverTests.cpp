#include "../Runtime/Warping/MotionWarpingSolver.h"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    const WarpTarget invalid{false, {10.0f, 0.0f, 0.0f}, 3.0f};
    const WarpCorrection skipped = MotionWarpingSolver::solve({}, 0.0f, invalid, {1.0f, 0.5f});
    if (skipped.applied) return 1;

    const WarpTarget target{true, {10.0f, 0.0f, 0.0f}, 2.0f};
    const WarpCorrection correction = MotionWarpingSolver::solve({}, 0.0f, target, {1.0f, 0.5f});
    if (!correction.applied || !correction.clamped) return 1;
    if (std::abs(correction.translation.x - 1.0f) >= 0.0001f) return 1;
    if (std::abs(correction.rotation - 0.5f) >= 0.0001f) return 1;
    std::cout << "MotionWarpingSolverTests passed\n";
    return 0;
}
