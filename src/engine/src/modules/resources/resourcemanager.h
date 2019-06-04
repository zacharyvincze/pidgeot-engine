#pragma once

#include <map>
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "modules/renderer.h"

#include "modules/resources/texture.h"

class ResourceManager {
    public:
        ResourceManager(std::shared_ptr<Renderer> renderer);
        Pidgeot::Texture* loadTexture(const std::string filepath);
    private:
        std::map<std::string, Pidgeot::Texture*> m_textures;
        std::shared_ptr<Renderer> m_renderer;
};