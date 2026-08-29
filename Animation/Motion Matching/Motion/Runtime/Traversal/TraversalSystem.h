#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"
#include "../Query/MotionQueryDatabase.h"
#include "../Trajectory/MotionTrajectory.h"
#include "MotionMatchingCollision.h"
#include "../Warping/MotionWarpingSolver.h"

namespace motion {

struct TraversalDecision {
    bool valid = false;
    MotionEnvironmentContext environment;
    SearchResult search;
    WarpCorrection warp;
};

class TraversalSystem {
public:
    static TraversalDecision evaluate(const MotionQuery &query,
                                      const MotionTrajectory &trajectory,
                                      const MotionQueryDatabase &database,
                                      const MotionMatcher &matcher,
                                      const MotionMatchingCollisionWorld &world,
                                      const MotionMatchingCollisionProbe &forward,
                                      const MotionMatchingCollisionProbe &top,
                                      const MotionMatchingCollisionProbe &landing,
                                      const WarpTarget &warp_target,
                                      const WarpLimits &warp_limits,
                                      const MotionCandidate *fallback);
};

const ModuleDescriptor &module_traversalsystem();

} // namespace motion
