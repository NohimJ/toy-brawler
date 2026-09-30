#pragma once

#include <string>

namespace engine {

// TODO(you): thin wrapper around a compiled shader program. Load from
// assets/shaders/. Keep this backend-specific (a GL version compiles
// GLSL via glCreateShader; a Vulkan version compiles SPIR-V) rather than
// trying to make one class serve both - the abstraction point is
// RendererBackend, not this class.
class Shader {
public:
    explicit Shader(const std::string& vertex_path, const std::string& fragment_path);
};

} // namespace engine
