#include "ExampleTask.h"

ExampleTask::ExampleTask()
: m_renderer(Pidgeot::Engine::get().getRenderer()),
m_input(Pidgeot::Engine::get().getInput()),
m_entityManager(Pidgeot::Engine::get().getEntityManager()) {
    // m_entityManager.pushEntity(m_player.get());
    // m_entityManager.pushEntity(m_object.get());
    m_entityManager.pushEntity(new Player(0, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m_entityManager.pushEntity(new Object(i*48, j*48, 48, 48));
        }
    }
}

void ExampleTask::onUpdate() {
    if (m_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();
}

void ExampleTask::onRender() {
}