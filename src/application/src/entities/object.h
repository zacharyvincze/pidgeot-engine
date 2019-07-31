#pragma once

#include "engine.h"

class Object : public Pidgeot::Entity {
public:
    Object(int x, int y, int w, int h);

    void onRender();
    void onUpdate() {}

private:
    Pidgeot::Renderer& m_renderer;
};