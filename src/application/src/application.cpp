#include "application.h"

#include "managers/mapmanager.h"
#include "tasks/tasks.h"

Application::Application()
{
    APP_INFO("Initializing application");

    // Map loading
    getMapManager().loadMap(new Pidgeot::Map(0, 0, "resources/maps/cave.tmx", "resources/tilemaps/cavesofgallet.png"));

    // Create state and push back state tasks
    getStateManager().pushState(new Pidgeot::GameState("teststate"));
    getStateManager().getState("teststate").pushTask(new ExampleTask());
    getStateManager().getState("teststate").pushTask(new DebugTask());
    getStateManager().setActiveState("teststate");

    APP_INFO("Successfully initialized application");
}

Application::~Application()
{
}

Pidgeot::Engine* Pidgeot::createApplication()
{
    return new Application();
}