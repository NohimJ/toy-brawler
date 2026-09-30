#pragma once

#include <string>

struct GLFWwindow;

namespace engine {

// Thin RAII wrapper around a GLFW window + its OS-level input events.
// This is platform boilerplate, not engine design - there is one correct
// way to open a window, so it's implemented rather than stubbed.
class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool ShouldClose() const;
    void PollEvents() const;
    void SwapBuffers() const;

    GLFWwindow* Handle() const { return handle_; }

private:
    GLFWwindow* handle_ = nullptr;
};

} // namespace engine
