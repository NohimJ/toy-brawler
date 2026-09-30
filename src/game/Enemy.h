#pragma once

namespace game {

// TODO(you): the AI update job's payload - approach/circle/attack states
// for grunt and bruiser archetypes. Keep this a plain state machine
// (an enum + a switch, or a small table of function pointers) - a full
// behavior-tree framework is scope you don't need for two enemy types.
enum class EnemyState { Approach, Circle, Attack };

class Enemy {
public:
    void Update(float dt);

private:
    EnemyState state_ = EnemyState::Approach;
};

} // namespace game
