#include "modules/entitymanager.h"

#include "log.h"

namespace Pidgeot {
EntityManager::~EntityManager()
{
    removeAllEntities();
}

void EntityManager::pushEntity(Pidgeot::Entity* entity)
{
    if (entity->isCollidable())
        m_collidableEntities.insert(std::pair<size_t, Entity*>(entity->getID(), entity));
    if (entity->isFixed())
        m_fixedEntities.insert(std::pair<size_t, Entity*>(entity->getID(), entity));
    m_entities.insert(std::pair<size_t, Entity*>(entity->getID(), entity));
}

void EntityManager::removeEntity(Entity* entity)
{
    if (entity->isCollidable())
        m_collidableEntities.erase(entity->getID());
    if (entity->isFixed())
        m_fixedEntities.erase(entity->getID());
    m_entities.erase(entity->getID());
}

void EntityManager::removeAllEntities()
{
    m_collidableEntities.clear();
    m_fixedEntities.clear();

    // Free memory from all pointers and clear data from map containing all entities
    for (std::unordered_map<size_t, Entity*>::iterator i = m_entities.begin(); i != m_entities.end(); i++) {
        delete (i->second);
    }
    m_entities.clear();
}

void EntityManager::onUpdate()
{
    for (std::unordered_map<size_t, Entity*>::iterator i = m_entities.begin(); i != m_entities.end(); i++) {
        i->second->onUpdate();
    }

    // Deal with collisions between collidable entities
    // TODO: Optimize this function, iterating through every entity will exponentially increase the processing power required
    for (std::unordered_map<size_t, Entity*>::iterator i = m_collidableEntities.begin(); i != m_entities.end(); i++) {
        i->second->setColliding(false);
        for (std::unordered_map<size_t, Entity*>::iterator entity = m_collidableEntities.begin(); entity != m_collidableEntities.end(); entity++) {
            // Check that the entity is not the current entity being handled
            if (i->second->getID() != entity->second->getID()) {
                if (i->second->checkCollision(entity->second))
                    i->second->setColliding(true);
            }
        }
    }
}

void EntityManager::onRender()
{
    for (std::unordered_map<size_t, Entity*>::iterator i = m_entities.begin(); i != m_entities.end(); i++) {
        i->second->onRender();
    }
}
}