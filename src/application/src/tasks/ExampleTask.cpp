#include "ExampleTask.h"

ExampleTask::ExampleTask()
: m_renderer(Pidgeot::Engine::get().getRenderer()),
m_input(Pidgeot::Engine::get().getInput()) {}

void ExampleTask::onUpdate() {
    if (m_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();
}

void ExampleTask::onRender() {
    m_renderer.setDrawColor(0,0,0,0);
    m_renderer.clear();
    m_renderer.present();
}