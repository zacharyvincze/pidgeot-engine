#pragma once

#include <unordered_map>

#include "modules/entity.h"

namespace Pidgeot {
    class EntityManager {
        public:
            void pushEntity(Pidgeot::Entity* entity);
            void removeEntity(Entity* entity);
            void removeAllEntities();

            inline int getCollidableCount() { return m_collidableEntities.size(); }
            inline int getFixedCount() { return m_fixedEntities.size(); }
            inline int getEntityCount() { return m_entities.size(); }
        private:
            std::unordered_map<size_t, Entity*> m_collidableEntities;
            std::unordered_map<size_t, Entity*> m_fixedEntities;
            std::unordered_map<size_t, Entity*> m_entities;
    };
}