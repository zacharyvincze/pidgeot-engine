#pragma once

#include "task.h"
#include "engine.h"
#include "player.h"

#include "modules/resources/animated_sprite.h"
#include "modules/resources/text.h"

class TaskDraw : public Pidgeot::Task {
    public:
        TaskDraw();
        void update();
    private:
        std::unique_ptr<Player> m_player;
        std::unique_ptr<Pidgeot::Text> m_text;
};