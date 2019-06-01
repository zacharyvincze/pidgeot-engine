#include "tasks/start.h"

void TaskStart::update() {
    Pidgeot::Engine::get().input().pollEvents();

    if (Pidgeot::Engine::get().input().wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();

    Pidgeot::Engine::get().renderer().setDrawColor(0,0,0,0xFF);
    Pidgeot::Engine::get().renderer().clear();
}