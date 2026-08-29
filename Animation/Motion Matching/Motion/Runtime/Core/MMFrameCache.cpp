#include "MMFrameCache.h"

#include <algorithm>
#include <utility>

namespace motion {

MMFrameCache::MMFrameCache(std::size_t capacity) : capacity_(capacity) {}

const SearchResult *MMFrameCache::find(std::uint64_t frame, const std::vector<float> &features) const {
    const auto it = std::find_if(entries_.begin(), entries_.end(), [&](const CachedSearch &entry) {
        return entry.frame == frame && entry.query_features == features;
    });
    return it == entries_.end() ? nullptr : &it->result;
}

void MMFrameCache::put(std::uint64_t frame, std::vector<float> features, SearchResult result) {
    const auto existing = std::find_if(entries_.begin(), entries_.end(), [&](const CachedSearch &entry) {
        return entry.frame == frame && entry.query_features == features;
    });
    if (existing != entries_.end()) {
        existing->result = std::move(result);
        existing->query_features = std::move(features);
        return;
    }
    entries_.insert(entries_.begin(), CachedSearch{frame, std::move(features), std::move(result)});
    if (entries_.size() > capacity_) entries_.pop_back();
}

void MMFrameCache::invalidate_frame(std::uint64_t frame) {
    entries_.erase(std::remove_if(entries_.begin(), entries_.end(),
                                  [frame](const CachedSearch &entry) { return entry.frame == frame; }), entries_.end());
}

void MMFrameCache::clear() { entries_.clear(); }
std::size_t MMFrameCache::size() const { return entries_.size(); }

const ModuleDescriptor &module_mmframecache() {
    static const ModuleDescriptor descriptor{
        "MMFrameCache", "Bounded frame/query cache with deterministic replacement and invalidation."};
    return descriptor;
}

} // namespace motion
