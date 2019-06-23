#pragma once

#include "engine.h"
#include "task.h"

class TaskStart : public Pidgeot::Task {
    public:
        TaskStart(Pidgeot::Input& input, Pidgeot::Renderer& renderer);
        void update();
    private:
        Pidgeot::Renderer& m_renderer;
        Pidgeot::Input& m_input;
};