#include "EntityManager.h"

namespace engine {

EntityManager::EntityManager() = default;

EntityId EntityManager::CreateEntity() {
    // TODO(you): recycle destroyed IDs via a free-list instead of only
    // ever incrementing - otherwise a long wave-survival session slowly
    // leaks EntityId space (not memory, just wasted ID range, but it's
    // the kind of detail worth getting right and worth mentioning in an
    // interview if asked "what happens after 4 billion entities").
    return next_id_++;
}

void EntityManager::DestroyEntity(EntityId id) {
    (void)id;
    // TODO(you): remove this entity's components from every
    // ComponentArray it's registered in, and return its ID to the
    // free-list.
}

} // namespace engine
