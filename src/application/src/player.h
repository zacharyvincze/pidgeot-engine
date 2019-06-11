#pragma once

#include <vector>

#include "modules/resources/animated_sprite.h"

class Player {
    public:
        Player(int x, int y);
        ~Player();

        void update();
        void draw();

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
    private:
        std::vector<Pidgeot::AnimatedSprite*> m_sprites;
        SDL_Rect m_position, m_bounding_box;    // Bounding box will eventually be converted into a rigid 2d body sometime during development

        const enum SpriteIndex {IDLE_UP, IDLE_DOWN, IDLE_LEFT, IDLE_RIGHT, WALKING_UP, WALKING_DOWN, WALKING_LEFT, WALKING_RIGHT};
        SpriteIndex m_current_sprite;

        const int PLAYER_SPEED = 1;
        int m_horizontal_velocity, m_vertical_velocity;
};