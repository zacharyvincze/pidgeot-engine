#pragma once

#include "task.h"
#include "engine.h"

#include "modules/resources/sprite.h"

class TaskDraw : public Pidgeot::Task {
    public:
        TaskDraw();
        void update();
    private:
        std::unique_ptr<Pidgeot::Sprite> m_ness;
};