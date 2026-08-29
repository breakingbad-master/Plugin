#pragma once

#include "MotionQueryDatabase.h"
#include "../Core/MMModule.h"

#include <cstdint>
#include <string>

namespace motion {

class MotionQueryDatabaseSerializer {
public:
    static bool save(const MotionQueryDatabase &database, const std::string &path, std::uint32_t version = 1);
    static bool load(MotionQueryDatabase &database, const std::string &path, std::uint32_t expected_version = 1);
};

const ModuleDescriptor &module_motionquerydatabaseserializer();

} // namespace motion
