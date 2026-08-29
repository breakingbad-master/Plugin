#include "MotionQueryDatabaseSerializer.h"

#include <fstream>
#include <limits>

namespace motion {
namespace {
constexpr std::uint32_t kMagic = 0x4D4D4442; // MMDB
constexpr std::uint32_t kMaxSamples = 1000000;
constexpr std::uint32_t kMaxTags = 128;
constexpr std::uint32_t kMaxFeatures = 4096;

bool write_string(std::ofstream &out, const std::string &value) {
    const auto size = static_cast<std::uint32_t>(value.size());
    out.write(reinterpret_cast<const char *>(&size), sizeof(size));
    out.write(value.data(), size);
    return static_cast<bool>(out);
}

bool read_string(std::ifstream &in, std::string &value, std::uint32_t max_size = 4096) {
    std::uint32_t size = 0;
    in.read(reinterpret_cast<char *>(&size), sizeof(size));
    if (!in || size > max_size) return false;
    value.resize(size);
    in.read(value.data(), size);
    return static_cast<bool>(in);
}
} // namespace

bool MotionQueryDatabaseSerializer::save(const MotionQueryDatabase &database, const std::string &path,
                                         std::uint32_t version) {
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out || database.size() > kMaxSamples) return false;
    const auto sample_count = static_cast<std::uint32_t>(database.size());
    out.write(reinterpret_cast<const char *>(&kMagic), sizeof(kMagic));
    out.write(reinterpret_cast<const char *>(&version), sizeof(version));
    out.write(reinterpret_cast<const char *>(&sample_count), sizeof(sample_count));
    for (const MotionCandidate &sample : database.samples()) {
        if (!write_string(out, sample.clip_id)) return false;
        const auto frame = static_cast<std::uint64_t>(sample.frame);
        const auto feature_count = static_cast<std::uint32_t>(sample.features.size());
        const auto tag_count = static_cast<std::uint32_t>(sample.tags.size());
        out.write(reinterpret_cast<const char *>(&frame), sizeof(frame));
        out.write(reinterpret_cast<const char *>(&feature_count), sizeof(feature_count));
        if (feature_count > kMaxFeatures) return false;
        out.write(reinterpret_cast<const char *>(sample.features.data()), sizeof(float) * feature_count);
        out.write(reinterpret_cast<const char *>(&tag_count), sizeof(tag_count));
        if (tag_count > kMaxTags) return false;
        for (const std::string &tag : sample.tags) if (!write_string(out, tag)) return false;
        out.write(reinterpret_cast<const char *>(&sample.max_obstacle_height), sizeof(float));
        out.write(reinterpret_cast<const char *>(&sample.min_clearance), sizeof(float));
        out.write(reinterpret_cast<const char *>(&sample.min_speed), sizeof(float));
        out.write(reinterpret_cast<const char *>(&sample.max_speed), sizeof(float));
        const auto fallback = static_cast<std::uint8_t>(sample.fallback ? 1 : 0);
        out.write(reinterpret_cast<const char *>(&fallback), sizeof(fallback));
    }
    return static_cast<bool>(out);
}

bool MotionQueryDatabaseSerializer::load(MotionQueryDatabase &database, const std::string &path,
                                         std::uint32_t expected_version) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return false;
    std::uint32_t magic = 0, version = 0, sample_count = 0;
    in.read(reinterpret_cast<char *>(&magic), sizeof(magic));
    in.read(reinterpret_cast<char *>(&version), sizeof(version));
    in.read(reinterpret_cast<char *>(&sample_count), sizeof(sample_count));
    if (!in || magic != kMagic || version != expected_version || sample_count > kMaxSamples) return false;
    MotionQueryDatabase loaded;
    loaded.reserve(sample_count);
    for (std::uint32_t i = 0; i < sample_count; ++i) {
        MotionCandidate sample;
        if (!read_string(in, sample.clip_id)) return false;
        std::uint64_t frame = 0;
        std::uint32_t feature_count = 0, tag_count = 0;
        in.read(reinterpret_cast<char *>(&frame), sizeof(frame));
        in.read(reinterpret_cast<char *>(&feature_count), sizeof(feature_count));
        if (!in || feature_count > kMaxFeatures) return false;
        sample.frame = static_cast<std::size_t>(frame);
        sample.features.resize(feature_count);
        in.read(reinterpret_cast<char *>(sample.features.data()), sizeof(float) * feature_count);
        in.read(reinterpret_cast<char *>(&tag_count), sizeof(tag_count));
        if (!in || tag_count > kMaxTags) return false;
        sample.tags.reserve(tag_count);
        for (std::uint32_t tag = 0; tag < tag_count; ++tag) {
            std::string value;
            if (!read_string(in, value)) return false;
            sample.tags.push_back(std::move(value));
        }
        in.read(reinterpret_cast<char *>(&sample.max_obstacle_height), sizeof(float));
        in.read(reinterpret_cast<char *>(&sample.min_clearance), sizeof(float));
        in.read(reinterpret_cast<char *>(&sample.min_speed), sizeof(float));
        in.read(reinterpret_cast<char *>(&sample.max_speed), sizeof(float));
        std::uint8_t fallback = 0;
        in.read(reinterpret_cast<char *>(&fallback), sizeof(fallback));
        if (!in) return false;
        sample.fallback = fallback != 0;
        loaded.add(std::move(sample));
    }
    database = std::move(loaded);
    return true;
}

const ModuleDescriptor &module_motionquerydatabaseserializer() {
    static const ModuleDescriptor descriptor{
        "MotionQueryDatabaseSerializer", "Versioned bounded binary save/load for searchable motion samples."};
    return descriptor;
}

} // namespace motion
