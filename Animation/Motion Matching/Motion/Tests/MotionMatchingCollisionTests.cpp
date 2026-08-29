#include "../Runtime/Traversal/MotionMatchingCollision.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace motion;

class FakeWorld : public MotionMatchingCollisionWorld {
public:
    MotionMatchingCollisionResult probe(const MotionMatchingCollisionProbe &probe) const override {
        MotionMatchingCollisionResult result;
        if (probe.id == "forward") {
            result.hit = true; result.blocking = true; result.distance = 1.0f;
            result.obstacle_height = 0.8f; result.surface_tag = "concrete";
        } else if (probe.id == "top") {
            result.hit = true; result.clearance = 1.3f; result.point = {0.0f, 0.8f, 0.0f};
        } else if (probe.id == "landing") {
            result.hit = true; result.clearance = 1.5f; result.point = {0.0f, 0.0f, 2.0f};
        }
        return result;
    }
};

int main() {
    FakeWorld world;
    MotionMatchingCollisionProbe forward;
    forward.id = "forward";
    MotionMatchingCollisionProbe top;
    top.id = "top";
    MotionMatchingCollisionProbe landing;
    landing.id = "landing";
    TraversalCandidate candidate;
    assert(MotionMatchingCollision::build_traversal_candidate(world, forward, top, landing, "vault", 1.0f, candidate));
    assert(candidate.type == "vault");
    MotionEnvironmentContext environment = MotionMatchingCollision::build_environment(world, forward, top, landing);
    assert(environment.valid && environment.blocked);
    assert(environment.obstacle_height == 0.8f);

    class BlockedLandingWorld final : public FakeWorld {
    public:
        MotionMatchingCollisionResult probe(const MotionMatchingCollisionProbe &probe) const override {
            auto result = FakeWorld::probe(probe);
            if (probe.id == "landing") result.blocking = true;
            return result;
        }
    } blocked_world;
    assert(!MotionMatchingCollision::build_traversal_candidate(blocked_world, forward, top, landing, "vault", 1.0f, candidate));
    std::cout << "MotionMatchingCollisionTests passed\n";
}
