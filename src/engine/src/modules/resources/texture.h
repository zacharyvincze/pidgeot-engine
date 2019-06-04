#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace Pidgeot {
    class Texture {
        public:
            Texture(const std::string path, SDL_Texture* texture) : m_path(path), m_texture(texture) {}
            ~Texture() { SDL_DestroyTexture(m_texture); }

            inline std::string getName() { return m_path; }
            inline SDL_Texture* getTexture() { return m_texture; }
        private:
            std::string m_path;
            SDL_Texture* m_texture;
    };
}