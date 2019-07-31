#pragma once

#include <string>

#include <SDL2/SDL.h>

namespace Pidgeot {
class Camera {
public:
    Camera(const std::string id, int x, int y, int width, int height);
    ~Camera();

    inline std::string getID() { return m_id; }
    SDL_Rect position;

private:
    std::string m_id;
};
}