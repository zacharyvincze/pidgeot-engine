#include "tasks/start.h"

#include <math.h>

# define M_PI 3.14159265358979323846

void TaskStart::update() {
    Pidgeot::Engine::get().getInput().reset();
    Pidgeot::Engine::get().getInput().pollEvents();

    if (Pidgeot::Engine::get().getInput().wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();

    float engine_ticks = Pidgeot::Engine::get().getTicks();
    // Pidgeot::Engine::get().renderer().setDrawColor(256*(sin(engine_ticks/1000)/2)+128,256*(sin(engine_ticks/1000+0.5*M_PI)/2)+128,256*(sin(engine_ticks/1000+M_PI)/2)+128,0xFF);
    Pidgeot::Engine::get().getRenderer().setDrawColor(0x00, 0x00, 0x00, 0xFF);
    Pidgeot::Engine::get().getRenderer().clear();
}