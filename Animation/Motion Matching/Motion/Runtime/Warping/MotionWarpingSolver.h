#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

namespace motion {

struct WarpTarget {
    bool valid = false;
    Vec3 position;
    float yaw = 0.0f;
};

struct WarpLimits {
    float max_translation = 0.0f;
    float max_rotation = 0.0f;
};

struct WarpCorrection {
    bool applied = false;
    bool clamped = false;
    Vec3 translation;
    float rotation = 0.0f;
};

class MotionWarpingSolver {
public:
    static WarpCorrection solve(const Vec3 &current_position, float current_yaw,
                                const WarpTarget &target, const WarpLimits &limits);
};

const ModuleDescriptor &module_motionwarpingsolver();

} // namespace motion
