#include "JobSystem.h"

#include <thread>

namespace engine {

JobSystem::JobSystem(std::size_t worker_count)
    : worker_count_(worker_count > 0 ? worker_count
                                     : std::max<std::size_t>(1, std::thread::hardware_concurrency() - 1))
{
    // TODO(you): spawn worker_count_ threads, each running a loop that
    // pulls jobs from its queue and executes them. Store the
    // std::thread objects so the destructor can join them.
}

JobSystem::~JobSystem() {
    // TODO(you): signal workers to stop and join every thread. Getting
    // shutdown right (no dangling jobs mid-flight, no thread leaked)
    // matters more than it seems - it's exactly the kind of thing that
    // passes locally and hangs in a demo.
}

} // namespace engine
