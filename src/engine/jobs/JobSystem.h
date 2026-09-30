#pragma once

#include <cstddef>
#include <functional>

namespace engine {

using JobFn = std::function<void()>;

// Fixed-size worker thread pool with dependency-counted jobs - not a
// general work-stealing scheduler (that's real extra scope, see the
// plan's note on bounding this honestly).
//
// TODO(you): this is the piece that reuses your SPSC ring buffer work
// directly:
//   - Spin up worker_count threads at construction, each pulling from its
//     own queue (or one shared queue guarded appropriately - decide and
//     be ready to justify the choice, same as you did for unique_ptr vs
//     shared_ptr in the order book).
//   - Submit(JobFn) -> a handle/counter the caller can wait on.
//   - SubmitAfter(JobFn, {handles...}) for the Animation-blend-depends-on-
//     both-AI-and-Physics case - a simple atomic counter per job,
//     decremented by each dependency on completion, job runs when it
//     hits zero.
//   - Wait(handle) for the main thread to sync before Render submit.
//   - Same acquire/release memory ordering discipline as the ring buffer:
//     get this wrong and you'll get intermittent, hard-to-repro corruption
//     under load, not a clean crash.
class JobSystem {
public:
    explicit JobSystem(std::size_t worker_count);
    ~JobSystem();

    JobSystem(const JobSystem&) = delete;
    JobSystem& operator=(const JobSystem&) = delete;

private:
    std::size_t worker_count_;
};

} // namespace engine
