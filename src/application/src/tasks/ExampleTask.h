#pragma once

#include "engine.h"
#include "modules/resources/text.h"

class ExampleTask : public Pidgeot::Task {
    public:
        ExampleTask();

        void onUpdate();
        void onRender();

    private:
        Pidgeot::Renderer& m_renderer;
        Pidgeot::Input& m_input;
};