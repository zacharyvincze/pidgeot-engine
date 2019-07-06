#include "modules/entitymanager.h"

namespace Pidgeot {
    void EntityManager::pushEntity(Pidgeot::Entity* entity) {
        if (entity->isCollidable()) m_collidableEntities.insert(std::pair<size_t, Entity*>(entity->getID(), entity));
        if (entity->isFixed()) m_fixedEntities.insert(std::pair<size_t, Entity*>(entity->getID(), entity));
        m_entities.insert(std::pair<size_t, Entity*>(entity->getID(), entity));
    }

    void EntityManager::removeEntity(Entity* entity) {
        if (entity->isCollidable()) m_collidableEntities.erase(entity->getID());
        if (entity->isFixed()) m_fixedEntities.erase(entity->getID());
        m_entities.erase(entity->getID());
    }

    void EntityManager::removeAllEntities() {
        // TODO: Iterate through each map and delete entities + deallocate pointers
    }
}