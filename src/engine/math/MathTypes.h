#pragma once

// Thin aliases over GLM. Deliberately not writing a hand-rolled Vec3/Quat
// from scratch here: GLM's SIMD-friendly types are correct, fast, and well
// tested, and "reimplement a battle-tested math library" burns weeks for
// zero portfolio signal. Your from-scratch SIMD work belongs in code that
// actually demonstrates something (e.g. a batch AABB overlap test in
// physics/Collision, or the ECS iteration itself) rather than in vector math
// nobody will look at twice.

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace engine {

using Vec2 = glm::vec2;
using Vec3 = glm::vec3;
using Vec4 = glm::vec4;
using Quat = glm::quat;
using Mat4 = glm::mat4;

} // namespace engine
