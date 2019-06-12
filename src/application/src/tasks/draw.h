#pragma once

#include "task.h"
#include "engine.h"
#include "player.h"

#include "modules/resources/animated_sprite.h"

class TaskDraw : public Pidgeot::Task {
    public:
        TaskDraw();
        void update();
    private:
        std::unique_ptr<Player> m_player;
};