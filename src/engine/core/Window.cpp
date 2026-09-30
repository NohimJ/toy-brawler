#include "Window.h"

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace engine {

Window::Window(int width, int height, const std::string& title) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    // NOTE: once you pick a renderer backend (Vulkan vs OpenGL), this hint
    // changes - GLFW_CLIENT_API set to GLFW_NO_API for Vulkan (you manage
    // the surface yourself), or GLFW_OPENGL_API + version hints for GL.
    // Left unset here deliberately: this is the renderer decision from the
    // plan, not something to default silently.
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    handle_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!handle_) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
}

Window::~Window() {
    if (handle_) {
        glfwDestroyWindow(handle_);
    }
    glfwTerminate();
}

bool Window::ShouldClose() const {
    return glfwWindowShouldClose(handle_);
}

void Window::PollEvents() const {
    glfwPollEvents();
}

void Window::SwapBuffers() const {
    glfwSwapBuffers(handle_);
}

} // namespace engine
