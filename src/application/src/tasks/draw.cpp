#include "tasks/draw.h"

TaskDraw::TaskDraw(Pidgeot::Renderer& renderer, Pidgeot::Input& input, Pidgeot::CameraManager& camera_manager, Pidgeot::ResourceManager& resource_manager, Pidgeot::Config& config) :
    m_renderer(renderer), m_input(input), m_camera_manager(camera_manager), m_resource_manager(resource_manager), m_config(config) {

    m_player = std::unique_ptr<Player>(new Player(0,0, m_renderer, m_camera_manager, m_resource_manager));
    m_text = std::unique_ptr<Pidgeot::Text>(new Pidgeot::Text(m_config.getOption("fontpath"), 8, 16, m_renderer, m_resource_manager));
}

void TaskDraw::update() {
    if (m_input.wasKeyHeld(SDL_SCANCODE_RIGHT)) m_player->moveRight();
    if (m_input.wasKeyHeld(SDL_SCANCODE_LEFT)) m_player->moveLeft();
    if (m_input.wasKeyHeld(SDL_SCANCODE_UP)) m_player->moveUp();
    if (m_input.wasKeyHeld(SDL_SCANCODE_DOWN)) m_player->moveDown();

    int camera_x = m_camera_manager.getActiveCamera().getPosition().x;
    int camera_y = m_camera_manager.getActiveCamera().getPosition().y;
    if (m_input.wasKeyHeld(SDL_SCANCODE_A))
        m_camera_manager.getActiveCamera().setPosition(camera_x+1, camera_y);

    m_player->update();
    m_player->draw();

    std::string debug_string = "X: " + std::to_string(m_player->getPosition().x) + " Y: " + std::to_string(m_player->getPosition().y);

    m_text->print("GUESS IT'S TIME TO IMPLEMENT SOME COLLISIONS :)", 0, 0);
    m_text->print("DEBUG MENU:", 0, Pidgeot::Engine::get().getWindowHeight()-32);
    m_text->print(debug_string, 0, Pidgeot::Engine::get().getWindowHeight()-16);
}