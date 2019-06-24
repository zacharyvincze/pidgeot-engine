#include "modules/renderer.h"

#include "engine.h"

namespace Pidgeot {
    Renderer::Renderer(uint32_t flags) :
    m_window(Engine::get().getWindow()) {

        s_renderer = SDL_CreateRenderer(m_window.getWindow(), -1, flags);
        SDL_RenderSetLogicalSize(s_renderer, m_window.getWidth(), m_window.getHeight());
        SDL_SetRenderDrawBlendMode(s_renderer, SDL_BLENDMODE_BLEND);
    }

    Renderer::~Renderer() {
        SDL_DestroyRenderer(s_renderer);
    }
}