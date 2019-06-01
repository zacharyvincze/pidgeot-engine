#pragma once

#include <map>
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "modules/renderer.h"

class ResourceManager {
    public:
        ResourceManager(std::shared_ptr<Renderer> renderer);
        SDL_Texture* loadTexture(const std::string filepath);
    private:
        std::map<std::string, SDL_Texture*> s_textures;
        std::shared_ptr<Renderer> s_renderer;
};