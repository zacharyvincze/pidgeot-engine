#pragma once

#include "engine.h"
#include "task.h"

class TaskEnd : public Pidgeot::Task {
    public:
        TaskEnd(Pidgeot::Renderer& renderer);
        void update();
    private:
        Pidgeot::Renderer& m_renderer;
};