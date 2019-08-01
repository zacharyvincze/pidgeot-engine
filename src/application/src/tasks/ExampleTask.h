#pragma once

#include "engine.h"
#include "entities/object.h"
#include "entities/player.h"
#include "modules/map/map.h"
#include "resources/text.h"

class ExampleTask : public Pidgeot::Task {
public:
    ExampleTask();

    void onUpdate();
    void onRender();

private:
    Pidgeot::Renderer& m_renderer;
    Pidgeot::Input& m_input;
    Pidgeot::EntityManager& m_entityManager;

    std::shared_ptr<Player> m_player;
    std::shared_ptr<Object> m_object;
};