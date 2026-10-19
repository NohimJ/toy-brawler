#include "Application.h"
#include <cstdio>
#include <GLFW/glfw3.h>

namespace engine {

Application::Application()
    : window_(1280, 720, "yakuza-toy"),
      jobs_(/* worker_count = */ 0) // TODO(you): 0 = "pick hardware_concurrency - 1" - decide that policy in JobSystem, not here.
{}

void Application::Run() {
    std::printf("OpenGL: %s\n", glGetString(GL_VERSION));
    while (!window_.ShouldClose()) {
        const float dt = clock_.Tick();
        window_.PollEvents();

        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        RunFrame(dt);

        window_.SwapBuffers();
    }
}

void Application::RunFrame(float dt) {
    // TODO(you): submit AI update + Physics update as parallel jobs against
    // entities_, then a dependent Animation blend job, then Render submit
    // on the main thread. See docs/job-graph.md for the dependency shape.
    (void)dt;
}

} // namespace engine
