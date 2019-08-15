#pragma once

#include "engine.h"
#include "entities/object.h"
#include "entities/player.h"
#include "resources/text.h"

class ExampleTask : public Pidgeot::Task {
public:
    ExampleTask();
    ~ExampleTask();

    void onUpdate();
    void onRender();

private:
    Pidgeot::Renderer& m_renderer;
    Pidgeot::Input& m_input;
    Pidgeot::EntityManager& m_entityManager;
    Pidgeot::MapManager& m_mapManager;
};