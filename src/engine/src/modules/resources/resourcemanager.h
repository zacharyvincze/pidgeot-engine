#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "modules/renderer.h"

#include "modules/resources/texture.h"

class ResourceManager {
    public:
        ResourceManager(std::shared_ptr<Renderer> renderer);

        template <class T> Pidgeot::Texture* get(const std::string filepath);
    private:
        std::unordered_map<std::string, Pidgeot::Texture*> m_textures;
        std::shared_ptr<Renderer> m_renderer;
};