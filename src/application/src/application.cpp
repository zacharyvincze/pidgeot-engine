#include "application.h"

#include "states/states.h"

Application::Application() {
    APP_INFO("Initializing application");
    getStateManager().pushState(new TestState("main_test"));
    getStateManager().setActiveState("main_test");

    getCameraManager().pushCamera(new Pidgeot::Camera("main", 0,0,getWindowWidth(), getWindowHeight()));
    getCameraManager().setActiveCamera("main");
    APP_INFO("Successfully initialized application");
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}