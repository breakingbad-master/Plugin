#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <cstdint>
#include <vector>

namespace motion {

struct CachedSearch {
    std::uint64_t frame = 0;
    std::vector<float> query_features;
    SearchResult result;
    std::uint64_t use_tick = 0;
};

class MotionQuerySearchCache {
public:
    explicit MotionQuerySearchCache(std::size_t capacity = 32);
    const SearchResult *find(std::uint64_t frame, const std::vector<float> &features);
    void put(std::uint64_t frame, std::vector<float> features, SearchResult result);
    void invalidate_frame(std::uint64_t frame);
    void clear();
    void set_capacity(std::size_t capacity);
    std::size_t size() const;
    std::size_t capacity() const;

private:
    std::size_t capacity_;
    std::uint64_t tick_ = 0;
    std::vector<CachedSearch> entries_;
};

const ModuleDescriptor &module_motionquerysearchcache();

} // namespace motion
