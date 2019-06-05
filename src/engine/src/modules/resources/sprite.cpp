#include "modules/resources/sprite.h"

namespace Pidgeot {
    Sprite::Sprite(const std::string texture, int source_x, int source_y, int width, int height) :
        m_source_rect({source_x, source_y, width, height}),
        m_destination_rect({0, 0, width, height}) {

        m_texture = Engine::get().resources().loadTexture(texture);
    }

    Sprite::~Sprite() {}
    
    void Sprite::draw(int x, int y) {
        m_destination_rect.x = x;
        m_destination_rect.y = y;
        Pidgeot::Engine::get().renderer().drawTexture(m_texture, &m_source_rect, &m_destination_rect);
    }
}