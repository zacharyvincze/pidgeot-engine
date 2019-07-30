#pragma once

#include <SDL2/SDL.h>
#include "modules/resources/texture.h"

namespace Pidgeot {
    class Entity {
        public:
            Entity(int x, int y, int width, int height, bool isFixed, bool isCollidable);
            ~Entity();

            virtual void onUpdate() {}
            virtual void onRender() {}

            inline bool isFixed() { return m_isFixed; }
            inline bool isCollidable() { return m_isCollidable; }

            inline bool setColliding(bool colliding) { m_isColliding = colliding; }

            inline size_t getID() { return m_id; }

            inline SDL_Rect getBoundingBox() { return m_boundingBox; }

            bool checkCollision(Entity* entity);
        protected:
            bool m_isFixed;
            bool m_isCollidable;
            SDL_Rect m_position;
            SDL_Rect m_boundingBox;
            bool m_isColliding;
        private:
            size_t m_id;
    };
}