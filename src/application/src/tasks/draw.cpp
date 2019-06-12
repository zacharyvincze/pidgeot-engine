#include "tasks/draw.h"

TaskDraw::TaskDraw() {
    m_player = std::unique_ptr<Player>(new Player(0,0));
}

void TaskDraw::update() {
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_RIGHT)) m_player->moveRight();
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_LEFT)) m_player->moveLeft();
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_UP)) m_player->moveUp();
    if (Pidgeot::Engine::get().input().wasKeyHeld(SDL_SCANCODE_DOWN)) m_player->moveDown();

    m_player->update();
    m_player->draw();
}