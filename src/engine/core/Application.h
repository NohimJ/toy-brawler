#pragma once

#include "Time.h"
#include "Window.h"
#include "engine/ecs/EntityManager.h"
#include "engine/jobs/JobSystem.h"

namespace engine {

// Owns the top-level objects and runs the main loop. This is the seam
// between "engine" and "game" - Application knows about ECS and the job
// system, but nothing about Kiryu, enemies, or wave logic. Game-specific
// systems get registered into it (see src/game/CMakeLists.txt and main.cpp)
// rather than Application depending on game/ directly.
class Application {
public:
    Application();
    void Run();

private:
    // One frame = one traversal of the job graph from the diagram:
    //   Frame start -> [AI update job, Physics update job] (parallel)
    //                -> Animation blend job -> Render submit
    // TODO(you): this is the actual engine-design work - implement the
    // dependency wiring here using JobSystem, once JobSystem itself exists.
    // Don't just call four functions in sequence on the main thread and
    // call it "job system" - the point is AI and Physics genuinely
    // overlapping on separate worker threads.
    void RunFrame(float dt);

    Window window_;
    FrameClock clock_;
    EntityManager entities_;
    JobSystem jobs_;
};

} // namespace engine
