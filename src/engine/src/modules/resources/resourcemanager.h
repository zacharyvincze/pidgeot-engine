#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "modules/renderer.h"

#include "modules/resources/texture.h"

namespace Pidgeot {
    class ResourceManager {
        public:
            ResourceManager(Pidgeot::Renderer& renderer);

            template <class T> Pidgeot::Texture* get(const std::string filepath);
        private:
            std::unordered_map<std::string, Pidgeot::Texture*> m_textures;
            Pidgeot::Renderer& m_renderer;
    };
}