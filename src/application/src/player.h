#pragma once

#include <vector>

#include "modules/resources/animated_sprite.h"

class Player {
    public:
        Player(int x, int y);
        ~Player();

        void update();
        inline void draw() { m_sprites[m_current_sprite]->draw(m_position.x, m_position.y); }

        inline void moveUp() { m_vertical_velocity = -PLAYER_SPEED; }
        inline void moveDown() { m_vertical_velocity = PLAYER_SPEED; }
        inline void moveLeft() { m_horizontal_velocity = -PLAYER_SPEED; }
        inline void moveRight() { m_horizontal_velocity = PLAYER_SPEED; }

        inline SDL_Rect getPosition() { return m_position; }
        inline SDL_Rect getBoundingBox() { return m_bounding_box; }
    private:
        std::vector<Pidgeot::Sprite*> m_sprites;
        SDL_Rect m_position, m_bounding_box;    // Bounding box will eventually be converted into a rigid 2d body sometime during development

        enum SpriteIndex {IDLE_UP, IDLE_DOWN, IDLE_LEFT, IDLE_RIGHT, WALKING_UP, WALKING_DOWN, WALKING_LEFT, WALKING_RIGHT};
        SpriteIndex m_current_sprite;

        const int PLAYER_SPEED = 1;
        int m_horizontal_velocity, m_vertical_velocity;
};