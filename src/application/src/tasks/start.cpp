#include "tasks/start.h"

#include <math.h>

# define M_PI 3.14159265358979323846

void TaskStart::update() {
    Pidgeot::Engine::get().input().reset();
    Pidgeot::Engine::get().input().pollEvents();

    if (Pidgeot::Engine::get().input().wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();

    float engine_ticks = Pidgeot::Engine::get().getTicks();
    Pidgeot::Engine::get().renderer().setDrawColor(256*(sin(engine_ticks/1000)/2)+128,256*(sin(engine_ticks/1000+0.5*M_PI)/2)+128,256*(sin(engine_ticks/1000+M_PI)/2)+128,0xFF);
    // Pidgeot::Engine::get().renderer().setDrawColor(0xFF,0xFF,0xFF,0xFF);
    Pidgeot::Engine::get().renderer().clear();
}