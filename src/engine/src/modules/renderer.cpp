#include "modules/renderer.h"

Renderer::Renderer(std::shared_ptr<Window> window, uint32_t flags) {
    s_renderer = SDL_CreateRenderer(window->getWindow(), -1, flags);
    SDL_RenderSetLogicalSize(s_renderer, window->getWidth(), window->getHeight());
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(s_renderer);
}