#include "tasks/end.h"

TaskEnd::TaskEnd(Pidgeot::Renderer& renderer) :
    m_renderer(renderer) {}

void TaskEnd::update() {
    m_renderer.present();
}