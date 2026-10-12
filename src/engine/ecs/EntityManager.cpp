#include "EntityManager.h"
#include "Components.h"

namespace engine {

EntityManager::EntityManager() = default;

EntityId EntityManager::CreateEntity() {
    if (!free_ids_.empty()) {
        const EntityId id = free_ids_.back();
        free_ids_.pop_back();
        return id;
    }
    return next_id_++;
}

void EntityManager::DestroyEntity(EntityId id) {
    transforms_.Remove(id);

    free_ids_.push_back(id);
}

} // namespace engine
