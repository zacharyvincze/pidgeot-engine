#include "player.h"

#include "engine.h"

const int PLAYER_HEIGHT =   48;
const int PLAYER_WIDTH =    32;

enum {
    IDLE_UP, IDLE_DOWN, IDLE_RIGHT, IDLE_LEFT,
    WALKING_UP, WALKING_DOWN, WALKING_RIGHT, WALKING_LEFT
};

const std::string PLAYER_TEXTURE = "resources/sprites/ness.png";

Player::Player(int x, int y)
: Entity(x, y, PLAYER_WIDTH, PLAYER_HEIGHT),
m_resourceManager(Pidgeot::Engine::get().getResourceManager()),
m_renderer(Pidgeot::Engine::get().getRenderer()),
m_currentSprite(IDLE_UP) {
    m_playerTexture = m_resourceManager.get<Pidgeot::Texture>(PLAYER_TEXTURE);

    m_playerSprites.resize(8);

    // Create player sprites
    m_playerSprites[IDLE_UP] = new Pidgeot::Sprite(PLAYER_TEXTURE, PLAYER_WIDTH*4, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    m_playerSprites[IDLE_DOWN] = new Pidgeot::Sprite(PLAYER_TEXTURE, 0, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    m_playerSprites[IDLE_RIGHT] = new Pidgeot::Sprite(PLAYER_TEXTURE, PLAYER_WIDTH*6, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    m_playerSprites[IDLE_LEFT] = new Pidgeot::Sprite(PLAYER_TEXTURE, PLAYER_WIDTH*2, 0, PLAYER_WIDTH, PLAYER_HEIGHT);

    // TODO: Add animated player sprites
}

void Player::onUpdate() {
}

void Player::onRender() {
    m_playerSprites[m_currentSprite]->draw(m_position.x, m_position.y);
}