#include "modules/resources/sprite.h"

namespace Pidgeot {
    Sprite::Sprite(const std::string texture, int source_x, int source_y, int width, int height, Pidgeot::Renderer& renderer, Pidgeot::ResourceManager& resource_manager) :
        m_source_rect({source_x, source_y, width, height}),
        m_destination_rect({0, 0, width, height}),
        m_renderer(renderer),
        m_resource_manager(resource_manager) {

        m_resource_manager.get<Pidgeot::Texture>(texture);
    }

    Sprite::~Sprite() {}
    
    void Sprite::draw(int x, int y) {
        m_destination_rect.x = x;
        m_destination_rect.y = y;
        m_renderer.drawTexture(m_texture, &m_source_rect, &m_destination_rect);
    }
}