#pragma once

#include <chrono>

namespace engine {

// Fixed-purpose delta-time clock. Not something to reinvent per-project;
// wraps std::chrono::steady_clock (monotonic, unaffected by system clock
// adjustments - what you want for frame timing, as opposed to
// system_clock which you'd use for wall-clock timestamps).
class FrameClock {
public:
    FrameClock() : last_(Clock::now()) {}

    // Call once per frame. Returns delta time in seconds since the last call.
    float Tick() {
        const auto now = Clock::now();
        const float dt = std::chrono::duration<float>(now - last_).count();
        last_ = now;
        return dt;
    }

private:
    using Clock = std::chrono::steady_clock;
    Clock::time_point last_;
};

} // namespace engine
