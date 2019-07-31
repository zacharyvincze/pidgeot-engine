#include "player.h"

#include "engine.h"

const int PLAYER_HEIGHT = 48;
const int PLAYER_WIDTH = 32;

enum {
    IDLE_UP,
    IDLE_DOWN,
    IDLE_RIGHT,
    IDLE_LEFT,
    WALKING_UP,
    WALKING_DOWN,
    WALKING_RIGHT,
    WALKING_LEFT
};

const std::string PLAYER_TEXTURE = "resources/sprites/ness.png";

Player::Player(int x, int y)
    : Entity(x, y, PLAYER_WIDTH, PLAYER_HEIGHT, false, true)
    , m_resourceManager(Pidgeot::Engine::get().getResourceManager())
    , m_renderer(Pidgeot::Engine::get().getRenderer())
    , m_input(Pidgeot::Engine::get().getInput())
    , m_currentSprite(IDLE_UP)
{
    m_playerTexture = m_resourceManager.get<Pidgeot::Texture>(PLAYER_TEXTURE);
    m_boundingBox = m_position;

    m_playerSprites.resize(8);

    // Create player sprites
    m_playerSprites[IDLE_UP] = new Pidgeot::Sprite(PLAYER_TEXTURE, PLAYER_WIDTH * 4, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    m_playerSprites[IDLE_DOWN] = new Pidgeot::Sprite(PLAYER_TEXTURE, 0, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    m_playerSprites[IDLE_RIGHT] = new Pidgeot::Sprite(PLAYER_TEXTURE, PLAYER_WIDTH * 6, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    m_playerSprites[IDLE_LEFT] = new Pidgeot::Sprite(PLAYER_TEXTURE, PLAYER_WIDTH * 2, 0, PLAYER_WIDTH, PLAYER_HEIGHT);

    // TODO: Add animated player sprites
}

void Player::onUpdate()
{
    // TODO: Temp input handling methods
    if (m_input.wasKeyHeld(SDL_SCANCODE_UP))
        m_position.y -= 1;
    if (m_input.wasKeyHeld(SDL_SCANCODE_DOWN))
        m_position.y += 1;
    if (m_input.wasKeyHeld(SDL_SCANCODE_LEFT))
        m_position.x -= 1;
    if (m_input.wasKeyHeld(SDL_SCANCODE_RIGHT))
        m_position.x += 1;
    m_boundingBox = m_position;
}

void Player::onRender()
{
    m_playerSprites[m_currentSprite]->draw(m_position.x, m_position.y);
}