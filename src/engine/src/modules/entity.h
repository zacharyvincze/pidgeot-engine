#pragma once

#include <SDL2/SDL.h>
#include "modules/resources/texture.h"

namespace Pidgeot {
    class Entity {
        public:
            Entity(int x, int y, int width, int height);
            ~Entity();

            virtual void onUpdate() {}
            virtual void onRender() {}

            inline bool isFixed() { return m_isFixed; }
            inline bool isCollidable() { return m_isCollidable; }

            inline size_t getID() { return m_id; }
        protected:
            bool m_isFixed;
            bool m_isCollidable;
            SDL_Rect m_position;
        private:
            size_t m_id;
    };
}