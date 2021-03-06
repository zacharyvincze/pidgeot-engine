#pragma once

#include "core/window.h"
#include <SDL2/SDL.h>
#include <memory>

#include "resources/texture.h"

namespace Pidgeot {
class Renderer {
public:
    Renderer(uint32_t flags);
    ~Renderer();

    // Basic renderer functions
    inline void clear() { SDL_RenderClear(s_renderer); }
    inline void setDrawColor(int r, int g, int b, int a) { SDL_SetRenderDrawColor(s_renderer, r, g, b, a); }
    inline void drawPoint(int x, int y) { SDL_RenderDrawPoint(s_renderer, x, y); }
    inline void present() { SDL_RenderPresent(s_renderer); }
    inline void drawTexture(Pidgeot::Texture* texture, SDL_Rect* source_rect, SDL_Rect* dest_rect) { SDL_RenderCopy(s_renderer, texture->getTexture(), source_rect, dest_rect); }
    inline void drawRect(SDL_Rect* destination_rect) { SDL_RenderDrawRect(s_renderer, destination_rect); }
    inline void drawFillRect(SDL_Rect* destination_rect) { SDL_RenderFillRect(s_renderer, destination_rect); }
    inline SDL_Renderer* getRenderer() { return s_renderer; }

private:
    SDL_Renderer* s_renderer;
    Window& m_window;
};
}