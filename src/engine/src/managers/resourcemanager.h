#pragma once

#include "core/renderer.h"
#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include <unordered_map>

#include "resources/texture.h"

namespace Pidgeot {
class ResourceManager {
public:
    ResourceManager();

    template <class T>
    Pidgeot::Texture* get(const std::string filepath);

private:
    std::unordered_map<std::string, Pidgeot::Texture*> m_textures;
    Renderer& m_renderer;
};
}