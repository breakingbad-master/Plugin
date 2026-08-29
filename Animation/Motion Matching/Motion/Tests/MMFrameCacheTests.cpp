#include "../Runtime/Core/MMFrameCache.h"

#include <iostream>

using namespace motion;

int main() {
    MMFrameCache cache(2);
    SearchResult first;
    first.evaluated = 1;
    cache.put(10, {1.0f, 2.0f}, first);
    const SearchResult *hit = cache.find(10, {1.0f, 2.0f});
    if (!hit || hit->evaluated != 1) return 1;
    SearchResult second;
    second.evaluated = 2;
    cache.put(11, {3.0f}, second);
    SearchResult third;
    third.evaluated = 3;
    cache.put(12, {4.0f}, third);
    if (cache.find(10, {1.0f, 2.0f}) != nullptr) return 1;
    cache.invalidate_frame(11);
    if (cache.find(11, {3.0f}) != nullptr || cache.size() != 1) return 1;
    std::cout << "MMFrameCacheTests passed\n";
    return 0;
}
