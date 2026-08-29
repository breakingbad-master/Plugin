#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

namespace motion {

struct Vec3 {
    float x = 0.0f, y = 0.0f, z = 0.0f;
    Vec3 operator+(const Vec3 &rhs) const;
    Vec3 operator-(const Vec3 &rhs) const;
    Vec3 operator*(float scalar) const;
    float length_squared() const;
};

struct TrajectoryPoint {
    float time = 0.0f;
    Vec3 position;
    Vec3 velocity;
    float facing_yaw = 0.0f;
};

struct MotionEnvironmentContext {
    bool valid = false;
    bool blocked = false;
    float obstacle_distance = 0.0f;
    float obstacle_height = 0.0f;
    float clearance = 0.0f;
    float ground_height = 0.0f;
    Vec3 surface_normal{0.0f, 1.0f, 0.0f};
    std::string surface_tag;
};

struct MotionQuery {
    std::vector<float> features;
    std::vector<TrajectoryPoint> trajectory;
    std::vector<std::string> tags;
    MotionEnvironmentContext environment;
    std::uint64_t frame = 0;
};

struct MotionCandidate {
    std::string clip_id;
    std::size_t frame = 0;
    std::vector<float> features;
    std::vector<std::string> tags;
    float max_obstacle_height = std::numeric_limits<float>::infinity();
    float min_clearance = 0.0f;
    float min_speed = 0.0f;
    float max_speed = std::numeric_limits<float>::infinity();
    bool fallback = false;
};

struct ScoreWeights {
    float feature = 1.0f;
    float trajectory = 1.0f;
    float contact = 1.0f;
    float continuity = 1.0f;
};

struct SearchBudget {
    std::size_t max_candidates = 256;
    std::size_t max_results = 5;
    float max_cost = std::numeric_limits<float>::infinity();
};

struct CandidateScore {
    const MotionCandidate *candidate = nullptr;
    float total = std::numeric_limits<float>::infinity();
    float feature_cost = 0.0f;
    float trajectory_cost = 0.0f;
    float contact_cost = 0.0f;
    float continuity_cost = 0.0f;
    bool filtered = false;
    std::string filter_reason;
};

struct SearchResult {
    CandidateScore selected;
    std::vector<CandidateScore> ranked;
    std::size_t evaluated = 0;
    std::size_t filtered = 0;
    bool used_fallback = true;
};

class MotionQueryDatabase {
public:
    void clear();
    void add_candidate(MotionCandidate candidate);
    const std::vector<MotionCandidate> &candidates() const;

private:
    std::vector<MotionCandidate> candidates_;
};

class MotionMatcher {
public:
    explicit MotionMatcher(ScoreWeights weights = {});
    SearchResult search(const MotionQuery &query, const MotionQueryDatabase &database,
                        const SearchBudget &budget, const MotionCandidate *fallback) const;

private:
    bool compatible(const MotionQuery &query, const MotionCandidate &candidate,
                    std::string &reason) const;
    CandidateScore score(const MotionQuery &query, const MotionCandidate &candidate,
                         const MotionCandidate *previous) const;
    ScoreWeights weights_;
};

} // namespace motion
