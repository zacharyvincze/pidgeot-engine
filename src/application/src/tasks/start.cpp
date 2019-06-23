#include "tasks/start.h"

#include <math.h>

# define M_PI 3.14159265358979323846

TaskStart::TaskStart(Pidgeot::Input& input, Pidgeot::Renderer& renderer) :
    m_input(input), m_renderer(renderer) {}

void TaskStart::update() {
    m_input.reset();
    m_input.pollEvents();

    if (m_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();

    float engine_ticks = Pidgeot::Engine::get().getTicks();
    // Pidgeot::Engine::get().renderer().setDrawColor(256*(sin(engine_ticks/1000)/2)+128,256*(sin(engine_ticks/1000+0.5*M_PI)/2)+128,256*(sin(engine_ticks/1000+M_PI)/2)+128,0xFF);
    m_renderer.setDrawColor(0x00, 0x00, 0x00, 0xFF);
    m_renderer.clear();
}