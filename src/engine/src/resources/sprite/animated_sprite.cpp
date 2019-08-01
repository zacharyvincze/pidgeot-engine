#include "resources/sprite/animated_sprite.h"

#include "engine.h"

namespace Pidgeot {
AnimatedSprite::AnimatedSprite(const std::string filepath, int source_x, int source_y, int width, int height, int frames, int frame_millis)
    : m_frame_count(frames)
    , m_frame_millis(frame_millis)
    , m_current_frame(0)
    , Sprite(filepath, source_x, source_y, width, height)
{

    for (int frame = 0; frame < m_frame_count; frame++) {
        m_sprites.push_back(new Sprite(filepath, source_x + (frame * width), source_y, width, height));
    }

    m_timer_start = Engine::get().getTicks();
}

AnimatedSprite::~AnimatedSprite()
{
    for (Sprite* sprite : m_sprites) {
        delete sprite;
    }
}

void AnimatedSprite::update()
{
    m_elapsed_time = Engine::get().getTicks() - m_timer_start;
    while (m_elapsed_time >= m_frame_millis) {
        m_current_frame++;
        m_elapsed_time -= m_frame_millis;
        if (m_current_frame > m_frame_count - 1)
            m_current_frame = 0;
        m_timer_start = Engine::get().getTicks();
    }
}

void AnimatedSprite::draw(int x, int y)
{
    m_sprites[m_current_frame]->draw(x, y);
}
}