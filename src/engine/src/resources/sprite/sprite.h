#pragma once

#include "engine.h"

#include "resources/texture.h"

namespace Pidgeot {
class Sprite {
public:
    Sprite(const std::string texture, int source_x, int source_y, int width, int height);
    ~Sprite();

    virtual void draw(int x, int y);
    virtual void update() {}

private:
    SDL_Rect m_destination_rect;
    SDL_Rect m_source_rect;

    Pidgeot::Texture* m_texture;

    Pidgeot::Renderer& m_renderer;
    Pidgeot::ResourceManager& m_resource_manager;
};
}