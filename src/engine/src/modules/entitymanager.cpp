#include "modules/entitymanager.h"

#include "log.h"

namespace Pidgeot {
    EntityManager::~EntityManager() {
        removeAllEntities();
    }

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
        m_collidableEntities.clear();
        m_fixedEntities.clear();

        // Free memory from all pointers and clear data from map containing all entities
        for (std::unordered_map<size_t, Entity*>::iterator i = m_entities.begin(); i != m_entities.end(); i++) {
            delete (i->second);
        }
        m_entities.clear();
    }

    void EntityManager::onUpdate() {
        for (std::unordered_map<size_t, Entity*>::iterator i = m_entities.begin(); i!= m_entities.end(); i++) {
            i->second->onUpdate();
            if (i->second->isCollidable()) {
                i->second->setColliding(false);
                // Check collision against every other entity contained within the map
                for (std::unordered_map<size_t, Entity*>::iterator j = m_collidableEntities.begin(); j != m_collidableEntities.end(); j++) {
                    if (j->second->getID() != i->second->getID()) {
                        if (i->second->checkCollision(j->second)) i->second->setColliding(true);
                    }
                }
            }
        }
    }

    void EntityManager::onRender() {
        for (std::unordered_map<size_t, Entity*>::iterator i = m_entities.begin(); i!= m_entities.end(); i++) {
            i->second->onRender();
        }
    }
}