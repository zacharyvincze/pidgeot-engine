#pragma once

#include <string>
#include <vector>

#include "modules/resources/resourcemanager.h"

namespace Pidgeot {
    class Text {
        public:
            Text(const std::string filepath, int char_width, int char_height, Pidgeot::Renderer& renderer, Pidgeot::ResourceManager& resource_manager);
            ~Text();
            void print(const std::string text, int x, int y);
        private:
            Pidgeot::Texture* m_font_texture;
            std::vector<SDL_Rect> m_char_map;

            int m_char_width, m_char_height;

            Pidgeot::Renderer& m_renderer;
            Pidgeot::ResourceManager& m_resource_manager;
    };
}