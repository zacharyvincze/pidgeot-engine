#pragma once

#include "modules/gamestate.h"

#include "engine.h"

class TestState : public Pidgeot::GameState {
    public:
        TestState(const std::string name, Pidgeot::Renderer& renderer, Pidgeot::ResourceManager& resource_manager, Pidgeot::CameraManager& camera_manager, Pidgeot::Input& input, Pidgeot::Config& config);
};