#include "tasks/draw.h"

TaskDraw::TaskDraw() {
    m_ness = std::unique_ptr<Pidgeot::AnimatedSprite>(new Pidgeot::AnimatedSprite("resources/sprites/ness.png", 0, 0, 32, 48, 8, 50));
}

void TaskDraw::update() {
    m_ness->update();
    m_ness->draw(0,0);
}