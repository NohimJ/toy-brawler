#pragma once

#include "engine/math/MathTypes.h"

namespace engine {

// Abstract interface so the rest of the engine (and game code) never
// spells out "Vulkan" or "OpenGL" directly - only this header does, via
// whichever concrete class you write against it (e.g. a future
// VulkanRenderer.h implementing this interface).
//
// TODO(you): this is the renderer-core phase from the plan. Suggested
// concrete first step: pick OpenGL 4.1 (last version macOS supports) for
// v1 - it gets you a triangle on screen in far less boilerplate than
// Vulkan, and the abstraction here means switching later doesn't ripple
// through game code. Only reach for Vulkan if the RGG-facing pitch
// specifically benefits from it (it's a stronger "systems" story, but a
// much longer road to a first triangle).
class RendererBackend {
public:
    virtual ~RendererBackend() = default;

    virtual void BeginFrame() = 0;
    virtual void SubmitMesh(/* Mesh handle, Mat4 transform, ... */) = 0;
    virtual void EndFrame() = 0;
};

} // namespace engine
