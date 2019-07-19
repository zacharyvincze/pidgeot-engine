#include "modules/resources/texture.h"

namespace Pidgeot {
    Texture::Texture(const std::string path, SDL_Texture* texture)
    : m_path(path), m_texture(texture) {
        m_width = 0;
        m_height = 0;
        SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    }
}