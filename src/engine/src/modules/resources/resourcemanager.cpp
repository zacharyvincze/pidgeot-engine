#include "modules/resources/resourcemanager.h"

#include "spdlog/spdlog.h"
#include <SDL2/SDL_image.h>

ResourceManager::ResourceManager(std::shared_ptr<Renderer> renderer) :
    m_renderer(renderer) {
}

Pidgeot::Texture* ResourceManager::loadTexture(const std::string filepath) {
    if (m_textures.count(filepath) <= 0) {
        SDL_Texture* image_texture = IMG_LoadTexture(m_renderer->getRenderer(), filepath.c_str());
        if (!image_texture) {
            spdlog::error("Unable to load texture {}: IMG_ERROR: {}", filepath.c_str(), IMG_GetError());
            exit(-1);
        }
        m_textures.insert(std::pair<std::string, Pidgeot::Texture*>(filepath, new Pidgeot::Texture(filepath, image_texture)));
        spdlog::debug("Created texture {} at {:p}", filepath.c_str(), (void*)image_texture);
    }
    return m_textures.at(filepath);
}