#pragma once

#include "modules/entity.h"
#include "resources/sprite/animated_sprite.h"
#include "resources/sprite/sprite.h"

#include <vector>

class Player : public Pidgeot::Entity {
public:
    Player(int x, int y);

    void onUpdate();
    void onRender();
    SDL_Rect getCollisionRect();

private:
    unsigned int m_currentSprite;
    std::vector<Pidgeot::Sprite*> m_playerSprites;
    Pidgeot::Texture* m_playerTexture;

    Pidgeot::ResourceManager& m_resourceManager;
    Pidgeot::Renderer& m_renderer;
    Pidgeot::Input& m_input;
};