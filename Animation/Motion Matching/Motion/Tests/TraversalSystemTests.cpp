#include "../Runtime/Traversal/TraversalSystem.h"

#include <cassert>
#include <iostream>

using namespace motion;

class TestWorld final : public MotionMatchingCollisionWorld {
public:
    MotionMatchingCollisionResult probe(const MotionMatchingCollisionProbe &probe) const override {
        MotionMatchingCollisionResult result;
        if (probe.id == "forward") {
            result.hit = true; result.blocking = true; result.distance = 1.0f;
            result.obstacle_height = 0.8f; result.surface_tag = "ground";
        } else if (probe.id == "top") {
            result.hit = true; result.clearance = 1.5f; result.point = {0.0f, 0.8f, 0.0f};
        } else if (probe.id == "landing") {
            result.hit = true; result.clearance = 1.5f; result.point = {0.0f, 0.0f, 2.0f};
        }
        return result;
    }
};

int main() {
    MotionQueryDatabase database;
    MotionCandidate vault{"vault_low", 42, {0.1f, 0.1f, 0.1f}, {"traversal", "vault", "ground"}, 1.0f, 0.5f};
    database.add(vault);
    MotionCandidate fallback{"idle", 0, {1.0f}, {"idle"}, 0.0f, 0.0f};
    MotionQuery query;
    query.features = {0.1f, 0.1f, 0.1f};
    query.tags = {"traversal", "vault", "ground"};
    MotionTrajectory trajectory;
    trajectory.set_points({{0.0f, {}, {1.0f, 0.0f, 0.0f}}});
    TestWorld world;
    MotionMatchingCollisionProbe forward; forward.id = "forward";
    MotionMatchingCollisionProbe top; top.id = "top";
    MotionMatchingCollisionProbe landing; landing.id = "landing";
    const TraversalDecision decision = TraversalSystem::evaluate(
        query, trajectory, database, MotionMatcher({1.0f, 0.0f, 0.0f, 0.0f}), world,
        forward, top, landing, {true, {0.1f, 0.0f, 0.0f}, 0.1f}, {0.5f, 0.5f}, &fallback);
    assert(decision.valid);
    assert(decision.search.selected.candidate->clip_id == "vault_low");
    assert(decision.environment.blocked);
    std::cout << "TraversalSystemTests passed\n";
    return 0;
}
