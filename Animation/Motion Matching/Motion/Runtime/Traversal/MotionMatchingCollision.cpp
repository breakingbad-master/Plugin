#include "MotionMatchingCollision.h"

#include <algorithm>

namespace motion {

MotionEnvironmentContext MotionMatchingCollision::build_environment(
    const MotionMatchingCollisionWorld &world,
    const MotionMatchingCollisionProbe &forward,
    const MotionMatchingCollisionProbe &top,
    const MotionMatchingCollisionProbe &landing) {
    const MotionMatchingCollisionResult obstacle = world.probe(forward);
    const MotionMatchingCollisionResult top_surface = world.probe(top);
    const MotionMatchingCollisionResult landing_space = world.probe(landing);
    MotionEnvironmentContext context;
    context.valid = obstacle.hit || top_surface.hit || landing_space.hit;
    context.blocked = obstacle.blocking;
    context.obstacle_distance = obstacle.distance;
    context.obstacle_height = obstacle.obstacle_height;
    context.clearance = std::min(top_surface.clearance, landing_space.clearance);
    context.ground_height = landing_space.point.y;
    context.surface_normal = obstacle.normal;
    context.surface_tag = obstacle.surface_tag;
    return context;
}

bool MotionMatchingCollision::build_traversal_candidate(
    const MotionMatchingCollisionWorld &world,
    const MotionMatchingCollisionProbe &forward,
    const MotionMatchingCollisionProbe &top,
    const MotionMatchingCollisionProbe &landing,
    const std::string &type,
    float min_clearance,
    TraversalCandidate &out) {
    out.obstacle = world.probe(forward);
    out.top_surface = world.probe(top);
    out.landing = world.probe(landing);
    if (!out.obstacle.hit || !out.top_surface.hit || !out.landing.hit) return false;
    if (!out.obstacle.blocking || out.landing.blocking) return false;
    if (out.top_surface.clearance < min_clearance || out.landing.clearance < min_clearance) return false;
    out.type = type;
    out.score = out.obstacle.distance + out.obstacle.obstacle_height * 0.5f;
    return true;
}

} // namespace motion
