#include "ExampleTask.h"

ExampleTask::ExampleTask()
: m_renderer(Pidgeot::Engine::get().getRenderer()),
m_input(Pidgeot::Engine::get().getInput()),
m_entityManager(Pidgeot::Engine::get().getEntityManager()) {
    m_entityManager.pushEntity(new Player(0, 0));
    m_map.reset(new Pidgeot::Map(0, 0, "resources/maps/cave.tmx", "resources/tilemaps/cavesofgallet.png"));
}

void ExampleTask::onUpdate() {
    if (m_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();
}

void ExampleTask::onRender() {
    m_map->onRender();
}