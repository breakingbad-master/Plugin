#include "../Runtime/Trajectory/MotionTrajectory.h"

#include <cassert>
#include <iostream>

using namespace motion;

int main() {
    MotionTrajectory trajectory;
    trajectory.set_points({
        {0.0f, {0.0f, -1.0f, 0.0f}, {10.0f, 0.0f, 0.0f}},
        {0.2f, {2.0f, -1.0f, 0.0f}, {10.0f, 0.0f, 0.0f}},
    });
    trajectory.constrain_speed(4.0f);
    assert(trajectory.points().front().velocity.length_squared() <= 16.001f);

    MotionEnvironmentContext environment;
    environment.valid = true;
    environment.blocked = true;
    environment.obstacle_distance = 1.0f;
    environment.obstacle_height = 0.8f;
    environment.clearance = 1.2f;
    environment.ground_height = 0.0f;

    TraversalCapability vault;
    vault.min_obstacle_height = 0.4f;
    vault.max_obstacle_height = 1.0f;
    vault.required_clearance = 1.0f;
    vault.landing_distance = 2.0f;
    vault.max_warp_translation = 0.2f;
    vault.max_entry_speed = 5.0f;
    assert(trajectory.refine_for_environment(environment, vault));
    assert(trajectory.points().front().position.y >= 0.0f);

    TraversalCapability too_low = vault;
    too_low.max_obstacle_height = 0.5f;
    const bool rejected = trajectory.supports_environment(environment, too_low);
    if (rejected) return 1;

    std::cout << "MotionTrajectoryTests passed\n";
    return 0;
}
