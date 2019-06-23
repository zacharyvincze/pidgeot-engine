#pragma once

#include "task.h"
#include "engine.h"
#include "player.h"

#include "modules/resources/animated_sprite.h"
#include "modules/resources/text.h"

class TaskDraw : public Pidgeot::Task {
    public:
        TaskDraw(Pidgeot::Renderer& renderer, Pidgeot::Input& input, Pidgeot::CameraManager& camera_manager, Pidgeot::ResourceManager& resource_manager, Pidgeot::Config& config);
        void update();
    private:
        std::unique_ptr<Player> m_player;
        std::unique_ptr<Pidgeot::Text> m_text;

        Pidgeot::Renderer& m_renderer;
        Pidgeot::Input& m_input;
        Pidgeot::CameraManager& m_camera_manager;
        Pidgeot::ResourceManager& m_resource_manager;
        Pidgeot::Config& m_config;
};