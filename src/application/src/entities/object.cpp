#include "entities/object.h"

Object::Object(int x, int y, int w, int h)
: Entity(x, y, w, h, false, true),
m_renderer(Pidgeot::Engine::get().getRenderer()) {
    m_boundingBox = m_position;
}

void Object::onRender() {
    if (m_isColliding) m_renderer.setDrawColor(0xFF, 0, 0, 0xFF);
    else m_renderer.setDrawColor(0, 0xFF, 0, 0xFF);
    m_renderer.drawFillRect(&m_boundingBox);
}