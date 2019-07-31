#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace Pidgeot {
class Texture {
public:
    Texture(const std::string path, SDL_Texture* texture);
    ~Texture() { SDL_DestroyTexture(m_texture); }

    inline std::string getName() { return m_path; }
    inline SDL_Texture* getTexture() { return m_texture; }

    inline int getWidth() { return m_width; }
    inline int getHeight() { return m_height; }

private:
    std::string m_path;
    SDL_Texture* m_texture;

    int m_width, m_height;
};
}