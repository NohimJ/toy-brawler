#pragma once

namespace game {

// TODO(you): decide wave count/pacing (open question from the plan -
// endless survival vs fixed gauntlet) and enemy density per wave. This
// is also your load-generator for the performance pass - however many
// enemies you spawn concurrently is the number your profiling numbers
// will be measured against, so pick it deliberately, not accidentally.
class WaveSpawner {
public:
    void Update(float dt);
};

} // namespace game
