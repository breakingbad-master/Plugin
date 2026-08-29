#include "TraversalSystem.h"

namespace motion {

TraversalDecision TraversalSystem::evaluate(const MotionQuery &query,
                                            const MotionTrajectory &trajectory,
                                            const MotionQueryDatabase &database,
                                            const MotionMatcher &matcher,
                                            const MotionMatchingCollisionWorld &world,
                                            const MotionMatchingCollisionProbe &forward,
                                            const MotionMatchingCollisionProbe &top,
                                            const MotionMatchingCollisionProbe &landing,
                                            const WarpTarget &warp_target,
                                            const WarpLimits &warp_limits,
                                            const MotionCandidate *fallback) {
    TraversalDecision decision;
    decision.environment = MotionMatchingCollision::build_environment(world, forward, top, landing);
    MotionQuery traversal_query = query;
    traversal_query.environment = decision.environment;
    decision.search = matcher.search(traversal_query, database, {}, fallback);
    if (!decision.search.selected.candidate || decision.search.selected.candidate->fallback) return decision;
    TraversalCapability capability;
    capability.max_obstacle_height = decision.search.selected.candidate->max_obstacle_height;
    capability.required_clearance = decision.search.selected.candidate->min_clearance;
    MotionTrajectory refined = trajectory;
    if (!refined.refine_for_environment(decision.environment, capability)) return decision;
    decision.warp = MotionWarpingSolver::solve({}, 0.0f, warp_target, warp_limits);
    if (!decision.warp.applied) return decision;
    decision.valid = true;
    return decision;
}

const ModuleDescriptor &module_traversalsystem() {
    static const ModuleDescriptor descriptor{
        "TraversalSystem", "End-to-end predictive environment, candidate search, trajectory refinement, and constrained warp."};
    return descriptor;
}

} // namespace motion
