#include "../Runtime/Query/MotionQueryDatabaseSerializer.h"

#include <cassert>
#include <cstdio>
#include <iostream>

using namespace motion;

int main() {
    const std::string path = "/tmp/motion_matching_database.mmdb";
    MotionQueryDatabase source;
    MotionCandidate sample{"vault_low", 42, {0.1f, 0.2f, 0.3f}, {"vault", "ground"}, 1.0f, 0.5f, 1.0f, 6.0f, false};
    source.add(sample);
    if (!MotionQueryDatabaseSerializer::save(source, path)) return 1;

    MotionQueryDatabase loaded;
    if (!MotionQueryDatabaseSerializer::load(loaded, path)) return 1;
    if (loaded.size() != 1) return 1;
    const MotionCandidate *result = loaded.get(0);
    if (!result || result->clip_id != "vault_low" || result->frame != 42) return 1;
    if (result->features.size() != 3 || result->tags.size() != 2) return 1;
    if (result->max_obstacle_height != 1.0f) return 1;
    if (MotionQueryDatabaseSerializer::load(loaded, path, 2)) return 1;
    std::remove(path.c_str());
    std::cout << "MotionQueryDatabaseSerializerTests passed\n";
    return 0;
}
