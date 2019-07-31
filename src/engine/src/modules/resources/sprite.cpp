#include "modules/resources/sprite.h"

namespace Pidgeot {
Sprite::Sprite(const std::string texture, int source_x, int source_y, int width, int height)
    : m_source_rect({ source_x, source_y, width, height })
    , m_destination_rect({ 0, 0, width, height })
    , m_renderer(Pidgeot::Engine::get().getRenderer())
    , m_resource_manager(Pidgeot::Engine::get().getResourceManager())
{

    m_texture = m_resource_manager.get<Pidgeot::Texture>(texture);
}

Sprite::~Sprite() {}

void Sprite::draw(int x, int y)
{
    m_destination_rect.x = x;
    m_destination_rect.y = y;
    m_renderer.drawTexture(m_texture, &m_source_rect, &m_destination_rect);
}
}