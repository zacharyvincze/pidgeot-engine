#include "player.h"

Player::Player(int x, int y) : m_position({x,y,0,0}) {
    // Cannot do anything with this until I get some resources to use I suppose
}

Player::~Player() {
    for (Pidgeot::AnimatedSprite* sprite : m_sprites) {
        delete sprite;
    }
}

void Player::update() {
    m_position.x += m_horizontal_velocity;
    m_position.y += m_vertical_velocity;
}

void Player::draw() {
    m_sprites[m_current_sprite]->draw(m_position.x, m_position.y);
}

void Player::moveUp() {
    m_vertical_velocity = -PLAYER_SPEED;
}

void Player::moveDown() {
    m_vertical_velocity = PLAYER_SPEED;
}

void Player::moveRight() { 
    m_horizontal_velocity = PLAYER_SPEED;
}

void Player::moveLeft() {
    m_vertical_velocity = -PLAYER_SPEED;
}