#include "ExampleTask.h"

ExampleTask::ExampleTask()
: m_renderer(Pidgeot::Engine::get().getRenderer()),
m_input(Pidgeot::Engine::get().getInput()) {
    m_text = std::unique_ptr<Pidgeot::Text>(new Pidgeot::Text("resources/fonts/apple-kid.png", 8, 16));
}

void ExampleTask::onUpdate() {
    if (m_input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) Pidgeot::Engine::get().quit();
}

void ExampleTask::onRender() {
    m_renderer.setDrawColor(0,0,0,0);
    m_renderer.clear();

    m_text->print("Welcome to PidgeotEngine!", 0, 0);
    m_text->print("Make yourself at home I guess...", 0, 16);

    m_renderer.present();
}