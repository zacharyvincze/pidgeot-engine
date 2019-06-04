#pragma once

#include "engine.h"

#include "modules/resources/texture.h"

namespace Pidgeot {
    class Sprite {
        public:
            Sprite(const std::string texture, int source_x, int source_y, int width, int height, int x, int y);
            ~Sprite();

            void draw();

            // Sprite manipulation
            void move(int x, int y);
        private:
            SDL_Rect m_destination_rect;
            SDL_Rect m_source_rect;

            Pidgeot::Texture* m_texture;
    };
}