#pragma once

#include "MMCore.h"
#include "MMModule.h"

#include <cstddef>
#include <cstdint>
#include <vector>

namespace motion {

struct CachedSearch {
    std::uint64_t frame = 0;
    std::vector<float> query_features;
    SearchResult result;
};

class MMFrameCache {
public:
    explicit MMFrameCache(std::size_t capacity = 32);
    const SearchResult *find(std::uint64_t frame, const std::vector<float> &features) const;
    void put(std::uint64_t frame, std::vector<float> features, SearchResult result);
    void invalidate_frame(std::uint64_t frame);
    void clear();
    std::size_t size() const;

private:
    std::size_t capacity_;
    std::vector<CachedSearch> entries_;
};

const ModuleDescriptor &module_mmframecache();

} // namespace motion
