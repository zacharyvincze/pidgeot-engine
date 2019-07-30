#pragma once

#include "engine.h"
#include "modules/resources/text.h"
#include "entities/player.h"
#include "entities/object.h"

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

        std::shared_ptr<Player> m_player;
        std::shared_ptr<Object> m_object;
};