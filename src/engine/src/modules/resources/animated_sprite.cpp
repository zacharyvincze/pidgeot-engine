#include "modules/resources/animated_sprite.h"

#include "engine.h"

namespace Pidgeot {
    AnimatedSprite::AnimatedSprite(const std::string filepath, int source_x, int source_y, int width, int height, int frames, int frame_millis) :
        m_frame_count(frames), m_frame_millis(frame_millis), m_current_frame(0) {
        
        for (int frame = 0; frame < m_frame_count; frame++) {
            m_sprites.push_back(new Sprite(filepath, source_x+(frame*width), source_y, width, height));
        }

        m_timer_start = Engine::get().getTicks();
    }

    AnimatedSprite::~AnimatedSprite() {
        for (Sprite* sprite : m_sprites) {
            delete sprite;
        }
    }

    void AnimatedSprite::update() {
        // TODO: Change current sprite index based on information given
    }

    void AnimatedSprite::draw(int x, int y) {
        m_sprites[m_current_frame]->draw(x, y);
    }
}