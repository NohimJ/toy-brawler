#pragma once
#include "engine/math/MathTypes.h"

namespace engine {

struct Transform {
    Vec3 position{0.0f};
    Quat rotation{1.0f, 0.0f, 0.0f, 0.0f};  // identity quaternion
};

}