#pragma once

#include "ComponentArray.h"

namespace engine {

// Allocates entity IDs and owns the fixed set of ComponentArray<T>
// instances for this project's small, fixed set of entity kinds
// (Kiryu, grunt, bruiser, thrown prop - see the plan's note on why a
// full dynamic archetype system is out of scope here).
//
// TODO(you): implement entity ID allocation (a simple free-list of
// recycled EntityId values is enough) and expose typed accessors, e.g.
// ComponentArray<Transform>& Transforms(); so systems can grab the dense
// array they need directly.
class EntityManager {
public:
    EntityManager();

    EntityId CreateEntity();
    void DestroyEntity(EntityId id);

private:
    EntityId next_id_ = 0;
};

} // namespace engine
