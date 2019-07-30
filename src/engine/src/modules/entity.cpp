#include "modules/entity.h"

#include "utils/uid.h"

namespace Pidgeot {
    Entity::Entity(int x, int y, int w, int h, bool isFixed, bool isCollidable)
    : m_position({x,y,w,h}),
    m_id(UID::generate()),
    m_isCollidable(isCollidable),
    m_isFixed(isFixed),
    m_isColliding(false) {}

    Entity::~Entity() {}

    bool Entity::checkCollision(Entity* entity) {
        // Check collision between two entities using axis-aligned collision detection
        SDL_Rect entity_bounding_box = entity->getBoundingBox();
        if (m_boundingBox.x < entity_bounding_box.x + entity_bounding_box.w &&
            m_boundingBox.x + m_boundingBox.w > entity_bounding_box.x &&
            m_boundingBox.y < entity_bounding_box.y + entity_bounding_box.h &&
            m_boundingBox.y + m_boundingBox.h > entity_bounding_box.y) {
            // A collision was detected, return true
            return true;     
        }
        return false;
    }
}