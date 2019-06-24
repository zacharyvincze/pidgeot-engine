#pragma once

#include "modules/resources/sprite.h"
#include <vector>

namespace Pidgeot {
    class AnimatedSprite : public Sprite {
        public:
            AnimatedSprite(const std::string filepath, int source_x, int source_y, int width, int height, int frames, int frame_millis);
            ~AnimatedSprite();

            void draw(int x, int y) override;
            void update() override;
            inline void reset();
        private:
            long m_timer_start, m_elapsed_time;
            int m_current_frame, m_frame_count, m_frame_millis;
            std::vector<Sprite*> m_sprites;
    };
}