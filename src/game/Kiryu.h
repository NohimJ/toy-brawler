#pragma once

#include "engine/ecs/ComponentArray.h"

namespace game {

// TODO(you): input -> movement/attack intent for the player-controlled
// entity. Keep this reading input and writing intent (e.g. "wants to
// attack this frame"); CombatSystem is what turns intent into hitboxes
// and damage, so the two stay decoupled and each stays testable alone.
class Kiryu {
public:
    void HandleInput();
};

} // namespace game
