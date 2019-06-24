#include "tasks/draw.h"

TaskDraw::TaskDraw() {
    m_player = std::unique_ptr<Player>(new Player(0,0));
    m_text = std::unique_ptr<Pidgeot::Text>(new Pidgeot::Text(Pidgeot::Engine::get().getConfig().getOption("fontpath"), 8, 16));
}

void TaskDraw::update() {
    if (Pidgeot::Engine::get().getInput().wasKeyHeld(SDL_SCANCODE_RIGHT)) m_player->moveRight();
    if (Pidgeot::Engine::get().getInput().wasKeyHeld(SDL_SCANCODE_LEFT)) m_player->moveLeft();
    if (Pidgeot::Engine::get().getInput().wasKeyHeld(SDL_SCANCODE_UP)) m_player->moveUp();
    if (Pidgeot::Engine::get().getInput().wasKeyHeld(SDL_SCANCODE_DOWN)) m_player->moveDown();

    int camera_x = Pidgeot::Engine::get().getCameraManager().getActiveCamera().getPosition().x;
    int camera_y = Pidgeot::Engine::get().getCameraManager().getActiveCamera().getPosition().y;
    if (Pidgeot::Engine::get().getInput().wasKeyHeld(SDL_SCANCODE_A))
        Pidgeot::Engine::get().getCameraManager().getActiveCamera().setPosition(camera_x+1, camera_y);

    m_player->update();
    m_player->draw();

    std::string debug_string = "X: " + std::to_string(m_player->getPosition().x) + " Y: " + std::to_string(m_player->getPosition().y);

    m_text->print("GUESS IT'S TIME TO IMPLEMENT SOME COLLISIONS :)", 0, 0);
    m_text->print("DEBUG MENU:", 0, Pidgeot::Engine::get().getWindowHeight()-32);
    m_text->print(debug_string, 0, Pidgeot::Engine::get().getWindowHeight()-16);
}