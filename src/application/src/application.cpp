#include "application.h"

#include "states/states.h"

Application::Application() {
    APP_INFO("Initializing application");
    stateManager().pushState(new TestState("main_test"));
    stateManager().setActiveState("main_test");

    cameraManager().pushCamera(new Pidgeot::Camera("main", 0,0,getWindowWidth(), getWindowHeight()));
    cameraManager().setActiveCamera("main");
    APP_INFO("Successfully initialized application");
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}