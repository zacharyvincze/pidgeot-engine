#include "player.h"

#include "log.h"

Player::Player(int x, int y)
    : m_position({x,y,32,48}), m_bounding_box({x,y,32,48}), m_horizontal_velocity(0), m_vertical_velocity(0) {
    APP_DEBUG("Created player at {:p}", (void*)this);

    m_current_sprite = IDLE_UP;

    // TODO: Create the rest of the sprites required for the player to have full movement animations
    m_sprites.push_back(new Pidgeot::AnimatedSprite("resources/sprites/ness.png", 0, 0, 32, 48, 8, 50));
}

Player::~Player() {
    for (Pidgeot::Sprite* sprite : m_sprites) {
        delete sprite;
    }
}

void Player::update() {
    m_position.x += m_horizontal_velocity;
    m_position.y += m_vertical_velocity;

    // Offset player position based on camera location
    m_position.x += Pidgeot::Engine::get().cameraManager().getActiveCamera().getPosition().x;
    m_position.y += Pidgeot::Engine::get().cameraManager().getActiveCamera().getPosition().y;

    // TODO: Bounding box will eventually have to differ from the player's position
    m_bounding_box = m_position;

    m_horizontal_velocity = 0;
    m_vertical_velocity = 0;

    m_sprites[m_current_sprite]->update();
}

void Player::draw() {
    m_sprites[m_current_sprite]->draw(m_position.x, m_position.y);

    // TODO: Add debug flags so that the following snippet is not included in the final build
    Pidgeot::Engine::get().renderer().setDrawColor(0xFF, 0x00, 0x00, 0x60);
    Pidgeot::Engine::get().renderer().drawFillRect(&m_bounding_box);
}