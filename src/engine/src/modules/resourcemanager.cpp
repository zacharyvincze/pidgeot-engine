#include "modules/resourcemanager.h"

#include "spdlog/spdlog.h"
#include <SDL2/SDL_image.h>

ResourceManager::ResourceManager(std::shared_ptr<Renderer> renderer) :
    s_renderer(renderer) {
}

SDL_Texture* ResourceManager::loadTexture(const std::string filepath) {
    if (s_textures.count(filepath) <= 0) {
        SDL_Texture* image_texture = IMG_LoadTexture(s_renderer->getRenderer(), filepath.c_str());
        if (!image_texture) {
            spdlog::error("Unable to load texture {}: IMG_ERROR: {}", filepath.c_str(), IMG_GetError());
            exit(-1);
        }
        s_textures.insert(std::pair<std::string, SDL_Texture*>(filepath, image_texture));
        spdlog::debug("Created texture {} at {:p}", filepath.c_str(), (void*)image_texture);
    }
    return s_textures.at(filepath);
}