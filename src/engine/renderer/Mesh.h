#pragma once

#include "engine/math/MathTypes.h"
#include <cstdint>
#include <vector>

namespace engine {

struct Vertex {
    Vec3 position;
    Vec3 normal;
    Vec2 uv;
};

// CPU-side mesh data. GPU upload (VBO/VAO for GL, buffer + memory for
// Vulkan) is a RendererBackend concern, not something this struct knows
// about - keeps mesh loading independent of the renderer backend choice.
struct MeshData {
    std::vector<Vertex> vertices;
    std::vector<std::uint32_t> indices;
};

} // namespace engine
