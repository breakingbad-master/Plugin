#include "MotionQueryDatabase.h"

#include <algorithm>
#include <utility>

namespace motion {

void MotionQueryDatabase::clear() { samples_.clear(); }
void MotionQueryDatabase::reserve(std::size_t count) { samples_.reserve(count); }
std::size_t MotionQueryDatabase::add(MotionCandidate candidate) {
    samples_.push_back(std::move(candidate));
    return samples_.size() - 1;
}
const MotionCandidate *MotionQueryDatabase::get(std::size_t index) const {
    return index < samples_.size() ? &samples_[index] : nullptr;
}
std::vector<std::size_t> MotionQueryDatabase::find_by_tag(std::string_view tag) const {
    std::vector<std::size_t> result;
    for (std::size_t i = 0; i < samples_.size(); ++i) {
        if (std::find(samples_[i].tags.begin(), samples_[i].tags.end(), tag) != samples_[i].tags.end()) {
            result.push_back(i);
        }
    }
    return result;
}
std::size_t MotionQueryDatabase::size() const { return samples_.size(); }
const std::vector<MotionCandidate> &MotionQueryDatabase::samples() const { return samples_; }

const ModuleDescriptor &module_motionquerydatabase() {
    static const ModuleDescriptor descriptor{
        "MotionQueryDatabase", "Owned searchable motion samples with safe lookup and tag filtering."};
    return descriptor;
}

} // namespace motion
