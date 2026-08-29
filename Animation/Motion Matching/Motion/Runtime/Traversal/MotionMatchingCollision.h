#pragma once

#include "../Core/MMCore.h"

#include <string>
#include <vector>

namespace motion {

enum class ProbeShape { Ray, Sphere, Capsule, Sweep };

struct MotionMatchingCollisionShape {
    ProbeShape shape = ProbeShape::Ray;
    float radius = 0.0f;
    float half_height = 0.0f;
    float length = 0.0f;
};

struct MotionMatchingCollisionProbe {
    std::string id;
    MotionMatchingCollisionShape shape;
    Vec3 origin;
    Vec3 direction{0.0f, 0.0f, 1.0f};
    float distance = 0.0f;
    std::vector<std::string> surface_tags;
};

struct MotionMatchingCollisionResult {
    bool hit = false;
    Vec3 point;
    Vec3 normal{0.0f, 1.0f, 0.0f};
    float distance = 0.0f;
    float obstacle_height = 0.0f;
    float clearance = 0.0f;
    std::string surface_tag;
    bool blocking = false;
};

struct TraversalCandidate {
    std::string type;
    MotionMatchingCollisionResult obstacle;
    MotionMatchingCollisionResult top_surface;
    MotionMatchingCollisionResult landing;
    float score = 0.0f;
};

class MotionMatchingCollisionWorld {
public:
    virtual ~MotionMatchingCollisionWorld() = default;
    virtual MotionMatchingCollisionResult probe(const MotionMatchingCollisionProbe &probe) const = 0;
};

class MotionMatchingCollision {
public:
    static MotionEnvironmentContext build_environment(const MotionMatchingCollisionWorld &world,
                                                       const MotionMatchingCollisionProbe &forward,
                                                       const MotionMatchingCollisionProbe &top,
                                                       const MotionMatchingCollisionProbe &landing);
    static bool build_traversal_candidate(const MotionMatchingCollisionWorld &world,
                                          const MotionMatchingCollisionProbe &forward,
                                          const MotionMatchingCollisionProbe &top,
                                          const MotionMatchingCollisionProbe &landing,
                                          const std::string &type,
                                          float min_clearance,
                                          TraversalCandidate &out);
};

} // namespace motion
