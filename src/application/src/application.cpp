#include "application.h"

#include "states/states.h"

Application::Application() {
    stateManager().pushState(new TestState("main_test"));
    stateManager().setActiveState("main_test");

    cameraManager().pushCamera(new Pidgeot::Camera("main", 0,0,getWindowWidth(), getWindowHeight()));
    cameraManager().setActiveCamera("main");
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}