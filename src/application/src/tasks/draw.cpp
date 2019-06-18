#include "tasks/draw.h"

TaskDraw::TaskDraw() {
    m_player = std::unique_ptr<Player>(new Player(0,0));
    m_text = std::unique_ptr<Pidgeot::Text>(new Pidgeot::Text(Pidgeot::Engine::get().config().getOption("fontpath"), 8, 16));
}

void TaskDraw::update() {
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_RIGHT)) m_player->moveRight();
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_LEFT)) m_player->moveLeft();
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_UP)) m_player->moveUp();
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_DOWN)) m_player->moveDown();

    m_player->update();
    m_player->draw();

    std::string debug_string = "X: " + std::to_string(m_player->getPosition().x) + " Y: " + std::to_string(m_player->getPosition().y);

    m_text->print("DEBUG MENU:", 0, Pidgeot::Engine::get().getWindowHeight()-32);
    m_text->print(debug_string, 0, Pidgeot::Engine::get().getWindowHeight()-16);
}