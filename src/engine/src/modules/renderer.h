#pragma once

#include <SDL2/SDL.h>
#include "modules/window.h"
#include <memory>

class Renderer {
    public:
        Renderer(std::shared_ptr<Window> window, uint32_t flags);
        ~Renderer();

        // Basic renderer functions
        inline void clear() { SDL_RenderClear(s_renderer); }
        inline void setDrawColor(int r, int g, int b, int a) { SDL_SetRenderDrawColor(s_renderer, r, g, b, a); }
        inline void drawPoint(int x, int y) { SDL_RenderDrawPoint(s_renderer, x, y); }
        inline void present() { SDL_RenderPresent(s_renderer); }
        inline void renderTexture(SDL_Texture* texture, SDL_Rect* source_rect, SDL_Rect* dest_rect) { SDL_RenderCopy(s_renderer, texture, source_rect, dest_rect); }
        inline SDL_Renderer* getRenderer() { return s_renderer; }
    private:
        SDL_Renderer* s_renderer;
};