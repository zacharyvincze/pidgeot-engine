#include "modules/resources/resourcemanager.h"

#include "log.h"
#include <SDL2/SDL_image.h>

#include "engine.h"

namespace Pidgeot {
    ResourceManager::ResourceManager() :
        m_renderer(Engine::get().getRenderer()) {
    }

    template<class T> Pidgeot::Texture* ResourceManager::get(const std::string filepath) {
        if (m_textures.count(filepath) <= 0) {
            SDL_Texture* image_texture = IMG_LoadTexture(m_renderer.getRenderer(), filepath.c_str());
            if (!image_texture) {
                ENGINE_ERROR("Unable to load texture {}: IMG_ERROR: {}", filepath.c_str(), IMG_GetError());
                exit(-1);
            }
            m_textures.insert(std::pair<std::string, Pidgeot::Texture*>(filepath, new Pidgeot::Texture(filepath, image_texture)));
            ENGINE_DEBUG("Created texture {} at {:p}", filepath.c_str(), (void*)image_texture);
        }
        return m_textures.at(filepath);
    }

    template Pidgeot::Texture* ResourceManager::get<Pidgeot::Texture>(const std::string);
}