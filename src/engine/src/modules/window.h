#pragma once

#include <SDL2/SDL.h>
#include <string>

class Window {
    public:
        Window(const std::string title, int width, int height, uint32_t flags);
        ~Window();
        
        inline SDL_Window* getWindow() { return s_window; }
        inline int getWidth() { return s_width; }
        inline int getHeight() { return s_height; }
    private:
        SDL_Window* s_window;
        int s_width, s_height;
};