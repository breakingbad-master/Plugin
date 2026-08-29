#include "MMCore.h"
#include "../Query/MotionQueryDatabase.h"

#include <algorithm>
#include <cmath>
#include <unordered_set>

namespace motion {

Vec3 Vec3::operator+(const Vec3 &rhs) const { return {x + rhs.x, y + rhs.y, z + rhs.z}; }
Vec3 Vec3::operator-(const Vec3 &rhs) const { return {x - rhs.x, y - rhs.y, z - rhs.z}; }
Vec3 Vec3::operator*(float scalar) const { return {x * scalar, y * scalar, z * scalar}; }
float Vec3::length_squared() const { return x * x + y * y + z * z; }

MotionMatcher::MotionMatcher(ScoreWeights weights) : weights_(weights) {}

static bool has_tag(const std::vector<std::string> &tags, std::string_view wanted) {
    return std::any_of(tags.begin(), tags.end(), [wanted](const std::string &tag) { return tag == wanted; });
}

static float squared_feature_distance(const std::vector<float> &a, const std::vector<float> &b) {
    if (a.size() != b.size()) return std::numeric_limits<float>::infinity();
    float sum = 0.0f;
    for (std::size_t i = 0; i < a.size(); ++i) {
        const float delta = a[i] - b[i];
        sum += delta * delta;
    }
    return sum;
}

bool MotionMatcher::compatible(const MotionQuery &query, const MotionCandidate &candidate,
                               std::string &reason) const {
    for (const std::string &tag : query.tags) {
        if (!has_tag(candidate.tags, tag)) {
            reason = "missing tag: " + tag;
            return false;
        }
    }
    if (query.environment.valid) {
        if (query.environment.blocked && candidate.max_obstacle_height < query.environment.obstacle_height) {
            reason = "obstacle exceeds animation capability";
            return false;
        }
        if (candidate.min_clearance > query.environment.clearance) {
            reason = "insufficient clearance";
            return false;
        }
        if (!query.environment.surface_tag.empty() && !has_tag(candidate.tags, query.environment.surface_tag)) {
            reason = "surface tag mismatch";
            return false;
        }
    }
    return true;
}

CandidateScore MotionMatcher::score(const MotionQuery &query, const MotionCandidate &candidate,
                                    const MotionCandidate *previous) const {
    CandidateScore result;
    result.candidate = &candidate;
    result.feature_cost = squared_feature_distance(query.features, candidate.features);
    if (!query.trajectory.empty() && !candidate.features.empty()) {
        const std::size_t sample_count = std::min(query.trajectory.size(), candidate.features.size() / 3);
        for (std::size_t i = 0; i < sample_count; ++i) {
            const Vec3 expected{candidate.features[i * 3], candidate.features[i * 3 + 1], candidate.features[i * 3 + 2]};
            result.trajectory_cost += (query.trajectory[i].position - expected).length_squared();
        }
    }
    const bool query_contact = has_tag(query.tags, "contact");
    const bool candidate_contact = has_tag(candidate.tags, "contact");
    result.contact_cost = query_contact == candidate_contact ? 0.0f : 1.0f;
    result.continuity_cost = previous && previous->clip_id == candidate.clip_id
        ? std::abs(static_cast<float>(candidate.frame) - static_cast<float>(previous->frame)) * 0.001f
        : 0.0f;
    result.total = weights_.feature * result.feature_cost + weights_.trajectory * result.trajectory_cost
        + weights_.contact * result.contact_cost + weights_.continuity * result.continuity_cost;
    return result;
}

SearchResult MotionMatcher::search(const MotionQuery &query, const MotionQueryDatabase &database,
                                   const SearchBudget &budget, const MotionCandidate *fallback) const {
    SearchResult result;
    const std::size_t limit = std::min(budget.max_candidates, database.samples().size());
    const MotionCandidate *previous = nullptr;
    for (std::size_t i = 0; i < limit; ++i) {
        const MotionCandidate &candidate = database.samples()[i];
        ++result.evaluated;
        std::string reason;
        if (!compatible(query, candidate, reason)) {
            CandidateScore rejected;
            rejected.candidate = &candidate;
            rejected.filtered = true;
            rejected.filter_reason = reason;
            result.ranked.push_back(std::move(rejected));
            ++result.filtered;
            continue;
        }
        CandidateScore scored = score(query, candidate, previous);
        if (scored.total <= budget.max_cost) result.ranked.push_back(std::move(scored));
    }
    std::stable_sort(result.ranked.begin(), result.ranked.end(), [](const CandidateScore &a, const CandidateScore &b) {
        if (a.filtered != b.filtered) return !a.filtered;
        if (a.total != b.total) return a.total < b.total;
        if (!a.candidate || !b.candidate) return a.candidate != nullptr;
        if (a.candidate->clip_id != b.candidate->clip_id) return a.candidate->clip_id < b.candidate->clip_id;
        return a.candidate->frame < b.candidate->frame;
    });
    if (result.ranked.size() > budget.max_results) result.ranked.resize(budget.max_results);
    if (!result.ranked.empty() && !result.ranked.front().filtered) {
        result.selected = result.ranked.front();
        result.used_fallback = false;
    } else if (fallback) {
        result.selected = score(query, *fallback, nullptr);
        result.selected.candidate = fallback;
        result.used_fallback = true;
    }
    return result;
}

SearchResult MotionMatcher::search_subset(const MotionQuery &query, const MotionQueryDatabase &database,
                                          const std::vector<std::size_t> &indices, const SearchBudget &budget,
                                          const MotionCandidate *fallback) const {
    SearchResult result;
    const std::size_t limit = std::min(budget.max_candidates, indices.size());
    const MotionCandidate *previous = nullptr;
    for (std::size_t i = 0; i < limit; ++i) {
        const MotionCandidate *candidate = database.get(indices[i]);
        if (!candidate) continue;
        ++result.evaluated;
        std::string reason;
        if (!compatible(query, *candidate, reason)) {
            CandidateScore rejected;
            rejected.candidate = candidate;
            rejected.filtered = true;
            rejected.filter_reason = reason;
            result.ranked.push_back(std::move(rejected));
            ++result.filtered;
            continue;
        }
        CandidateScore scored = score(query, *candidate, previous);
        if (scored.total <= budget.max_cost) result.ranked.push_back(std::move(scored));
    }
    std::stable_sort(result.ranked.begin(), result.ranked.end(), [](const CandidateScore &a, const CandidateScore &b) {
        if (a.filtered != b.filtered) return !a.filtered;
        if (a.total != b.total) return a.total < b.total;
        if (!a.candidate || !b.candidate) return a.candidate != nullptr;
        if (a.candidate->clip_id != b.candidate->clip_id) return a.candidate->clip_id < b.candidate->clip_id;
        return a.candidate->frame < b.candidate->frame;
    });
    if (result.ranked.size() > budget.max_results) result.ranked.resize(budget.max_results);
    if (!result.ranked.empty() && !result.ranked.front().filtered) {
        result.selected = result.ranked.front();
        result.used_fallback = false;
    } else if (fallback) {
        result.selected = score(query, *fallback, nullptr);
        result.selected.candidate = fallback;
        result.used_fallback = true;
    }
    return result;
}

} // namespace motion
