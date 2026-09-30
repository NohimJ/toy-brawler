#pragma once

#include "engine/math/MathTypes.h"
#include <cstdint>
#include <vector>

namespace engine {

struct Bone {
    Mat4 local_transform;
    std::int32_t parent_index; // -1 for root
};

// TODO(you): skeletal hierarchy + per-frame pose. This is the foundation
// the Kiryu + combat core phase builds on - get single-clip playback
// correct before attempting blending between clips.
struct Skeleton {
    std::vector<Bone> bones;
};

} // namespace engine
