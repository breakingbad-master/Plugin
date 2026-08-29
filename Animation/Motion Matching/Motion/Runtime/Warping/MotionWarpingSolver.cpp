#include "MotionWarpingSolver.h"

#include <algorithm>
#include <cmath>

namespace motion {

static float wrap_angle(float angle) {
    constexpr float pi = 3.14159265358979323846f;
    while (angle > pi) angle -= 2.0f * pi;
    while (angle < -pi) angle += 2.0f * pi;
    return angle;
}

WarpCorrection MotionWarpingSolver::solve(const Vec3 &current_position, float current_yaw,
                                          const WarpTarget &target, const WarpLimits &limits) {
    WarpCorrection result;
    if (!target.valid) return result;
    result.translation = target.position - current_position;
    const float max_translation = std::max(0.0f, limits.max_translation);
    const float distance_sq = result.translation.length_squared();
    if (distance_sq > max_translation * max_translation && distance_sq > 0.0f) {
        result.translation = result.translation * (max_translation / std::sqrt(distance_sq));
        result.clamped = true;
    }
    result.rotation = wrap_angle(target.yaw - current_yaw);
    const float max_rotation = std::max(0.0f, limits.max_rotation);
    if (std::abs(result.rotation) > max_rotation) {
        result.rotation = std::clamp(result.rotation, -max_rotation, max_rotation);
        result.clamped = true;
    }
    result.applied = true;
    return result;
}

const ModuleDescriptor &module_motionwarpingsolver() {
    static const ModuleDescriptor descriptor{
        "MotionWarpingSolver", "Validated target alignment with bounded translation and rotation correction."};
    return descriptor;
}

} // namespace motion
