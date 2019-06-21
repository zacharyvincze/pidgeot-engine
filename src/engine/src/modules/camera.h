#pragma once

#include <string>

#include <SDL2/SDL.h>

namespace Pidgeot {
    class Camera {
        public:
            Camera(const std::string name, int x, int y, int width, int height);
            ~Camera();

            inline void setPosition(int x, int y) { m_position.x = x; m_position.y = y; }
            inline std::string getName() { return m_name; }
            inline SDL_Rect getPosition() { return m_position; }
        private:
            SDL_Rect m_position;
            std::string m_name;
    };
}