#pragma once

#include "engine.h"
#include "imgui/imgui.h"

class DebugTask : public Pidgeot::Task {
public:
    void onRender();
};