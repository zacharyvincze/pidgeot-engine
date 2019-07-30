#include "ExampleTask.h"

ExampleTask::ExampleTask()
: m_renderer(Pidgeot::Engine::get().getRenderer()),
m_input(Pidgeot::Engine::get().getInput()),
m_entityManager(Pidgeot::Engine::get().getEntityManager()) {
    // m_entityManager.pushEntity(m_player.get());
    // m_entityManager.pushEntity(m_object.get());
    m_entityManager.pushEntity(new Player(0, 0));
    m_entityManager.pushEntity(new Object(50, 50, 48, 48));
}

void ExampleTask::onUpdate() {
    if (m_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();
}

void ExampleTask::onRender() {
}