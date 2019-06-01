#include "tasks/draw.h"

void TaskDraw::update() {
    Pidgeot::Engine::get().renderer().setDrawColor(0xFF,0xFF,0xFF,0xFF);
    Pidgeot::Engine::get().renderer().drawPoint(0,0);
}