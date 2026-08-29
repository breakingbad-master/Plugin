#include "../Runtime/Query/MotionQuerySearchCache.h"

#include <iostream>

using namespace motion;

static SearchResult result_for(std::size_t index) {
    SearchResult result;
    result.evaluated = index + 1;
    return result;
}

int main() {
    MotionQuerySearchCache cache(2);
    cache.put(1, {1.0f}, result_for(1));
    cache.put(2, {2.0f}, result_for(2));
    if (cache.size() != 2 || !cache.find(1, {1.0f})) return 1;
    cache.put(3, {3.0f}, result_for(3));
    if (cache.find(2, {2.0f}) != nullptr || cache.find(1, {1.0f}) == nullptr || cache.find(3, {3.0f}) == nullptr) return 1;
    cache.invalidate_frame(1);
    if (cache.find(1, {1.0f}) != nullptr || cache.size() != 1) return 1;
    cache.set_capacity(0);
    if (cache.size() != 0 || cache.capacity() != 0) return 1;
    cache.put(4, {4.0f}, result_for(4));
    if (cache.size() != 0) return 1;
    std::cout << "MotionQuerySearchCacheTests passed\n";
    return 0;
}
