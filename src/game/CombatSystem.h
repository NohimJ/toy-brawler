#pragma once

namespace game {

// TODO(you): hitbox/hurtbox overlap (built on engine::Overlaps), combo
// state machine, hit-stop, and the single Heat Action trigger condition.
// This is the phase the plan calls out as the biggest and most important
// - budget accordingly, and resist folding in a second Heat Action or a
// second enemy archetype before this one is genuinely satisfying.
class CombatSystem {
public:
    void Update(float dt);
};

} // namespace game
