#include "application.h"

#include "tasks/tasks.h"

Application::Application() {
    APP_INFO("Initializing application");

    // Create state and push back state tasks
    getStateManager().pushState(new Pidgeot::GameState("teststate"));
    getStateManager().getState("teststate").pushTask(new ExampleTask());
    getStateManager().setActiveState("teststate");

    APP_INFO("Successfully initialized application");
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}