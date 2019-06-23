#include "states/test.h"

#include "tasks/tasks.h"

TestState::TestState(const std::string name, Pidgeot::Renderer& renderer, Pidgeot::ResourceManager& resource_manager, Pidgeot::CameraManager& camera_manager, Pidgeot::Input& input, Pidgeot::Config& config) : GameState(name) {
    pushTask(new TaskStart(input, renderer));
    pushTask(new TaskDraw(renderer, input, camera_manager, resource_manager, config));
    pushTask(new TaskEnd(renderer));
}