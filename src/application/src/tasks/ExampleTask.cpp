#include "ExampleTask.h"

ExampleTask::ExampleTask()
: m_renderer(Pidgeot::Engine::get().getRenderer()),
m_input(Pidgeot::Engine::get().getInput()),
m_entityManager(Pidgeot::Engine::get().getEntityManager()) {
    m_entityManager.pushEntity(new Player(0, 0));
}

void ExampleTask::onUpdate() {
    if (m_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();
}

void ExampleTask::onRender() {
}