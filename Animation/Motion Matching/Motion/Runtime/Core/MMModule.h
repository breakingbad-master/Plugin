#pragma once

#include <string_view>

namespace motion {
struct ModuleDescriptor {
    std::string_view name;
    std::string_view responsibility;
};
} // namespace motion
