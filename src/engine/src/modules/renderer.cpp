#include "modules/renderer.h"

namespace Pidgeot {
    Renderer::Renderer(Window& window, uint32_t flags) {
        s_renderer = SDL_CreateRenderer(window.getWindow(), -1, flags);
        SDL_RenderSetLogicalSize(s_renderer, window.getWidth(), window.getHeight());
        SDL_SetRenderDrawBlendMode(s_renderer, SDL_BLENDMODE_BLEND);
    }

    Renderer::~Renderer() {
        SDL_DestroyRenderer(s_renderer);
    }
}