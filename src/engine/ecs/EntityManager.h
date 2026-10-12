#pragma once

#include "ComponentArray.h"
#include "Components.h"

namespace engine {

// Allocates entity IDs and owns the fixed set of ComponentArray<T>
// instances for this project's small, fixed set of entity kinds
// (Kiryu, grunt, bruiser, thrown prop - see the plan's note on why a
// full dynamic archetype system is out of scope here).

class EntityManager {
public:
    EntityManager();
    

    EntityId CreateEntity();
    void DestroyEntity(EntityId id);

    ComponentArray<Transform>& Transforms() { return transforms_; }

private:
    EntityId next_id_ = 0;
    std::vector<EntityId> free_ids_;

    ComponentArray<Transform> transforms_;
};

} 
