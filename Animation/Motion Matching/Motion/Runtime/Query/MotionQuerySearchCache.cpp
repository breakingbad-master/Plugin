#include "MotionQuerySearchCache.h"

#include <algorithm>
#include <utility>

namespace motion {

MotionQuerySearchCache::MotionQuerySearchCache(std::size_t capacity) : capacity_(capacity) {
    entries_.reserve(capacity_);
}

const SearchResult *MotionQuerySearchCache::find(std::uint64_t frame, const std::vector<float> &features) {
    for (auto &entry : entries_) {
        if (entry.frame == frame && entry.query_features == features) {
            entry.use_tick = ++tick_;
            return &entry.result;
        }
    }
    return nullptr;
}

void MotionQuerySearchCache::put(std::uint64_t frame, std::vector<float> features, SearchResult result) {
    if (capacity_ == 0) return;
    for (auto &entry : entries_) {
        if (entry.frame == frame && entry.query_features == features) {
            entry.result = std::move(result);
            entry.use_tick = ++tick_;
            return;
        }
    }
    if (entries_.size() >= capacity_) {
        const auto victim = std::min_element(entries_.begin(), entries_.end(),
            [](const CachedSearch &a, const CachedSearch &b) { return a.use_tick < b.use_tick; });
        if (victim != entries_.end()) *victim = CachedSearch{frame, std::move(features), std::move(result), ++tick_};
    } else {
        entries_.push_back(CachedSearch{frame, std::move(features), std::move(result), ++tick_});
    }
}

void MotionQuerySearchCache::invalidate_frame(std::uint64_t frame) {
    entries_.erase(std::remove_if(entries_.begin(), entries_.end(),
        [frame](const CachedSearch &entry) { return entry.frame == frame; }), entries_.end());
}

void MotionQuerySearchCache::clear() { entries_.clear(); }

void MotionQuerySearchCache::set_capacity(std::size_t capacity) {
    capacity_ = capacity;
    if (entries_.size() <= capacity_) return;
    std::sort(entries_.begin(), entries_.end(),
        [](const CachedSearch &a, const CachedSearch &b) { return a.use_tick > b.use_tick; });
    entries_.resize(capacity_);
}

std::size_t MotionQuerySearchCache::size() const { return entries_.size(); }
std::size_t MotionQuerySearchCache::capacity() const { return capacity_; }

const ModuleDescriptor &module_motionquerysearchcache() {
    static const ModuleDescriptor descriptor{
        "MotionQuerySearchCache", "Bounded LRU cache for repeated frame/query searches."};
    return descriptor;
}

} // namespace motion
