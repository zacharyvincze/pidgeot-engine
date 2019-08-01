#include "modules/window.h"

namespace Pidgeot {
Window::Window(const std::string title, int width, int height, uint32_t flags)
{
    s_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
    s_width = width;
    s_height = height;
    SDL_ShowCursor(SDL_FALSE);
}

Window::~Window()
{
    SDL_DestroyWindow(s_window);
}
}