#include "tasks/draw.h"

TaskDraw::TaskDraw() {
    m_ness = std::unique_ptr<Pidgeot::Sprite>(new Pidgeot::Sprite("resources/sprites/ness-front.png", 0, 0, 32, 48, 0, 0));
}

void TaskDraw::update() {
    m_ness->draw();
}