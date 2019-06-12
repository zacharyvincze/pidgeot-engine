#include "player.h"

#include "log.h"

Player::Player(int x, int y) : m_position({x,y,0,0}) {
    // Cannot do anything with this until I get some resources to use I suppose
    APP_DEBUG("Created player at {:p}", (void*)this);

    // Create animated sprites for use with player
    m_current_sprite = IDLE_UP;

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

    m_horizontal_velocity = 0;
    m_vertical_velocity = 0;

    m_sprites[m_current_sprite]->update();
}