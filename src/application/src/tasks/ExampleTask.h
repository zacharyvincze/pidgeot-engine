#pragma once

#include "engine.h"
#include "modules/resources/text.h"
#include "entities/player.h"

#include "modules/resources/map/map.h"

class ExampleTask : public Pidgeot::Task {
    public:
        ExampleTask();

        void onUpdate();
        void onRender();

    private:
        Pidgeot::Renderer& m_renderer;
        Pidgeot::Input& m_input;
        Pidgeot::EntityManager& m_entityManager;

        std::unique_ptr<Pidgeot::Map> m_map;
};