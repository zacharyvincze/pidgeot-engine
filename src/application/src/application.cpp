#include "application.h"

#include "states/states.h"

Application::Application() {
    stateManager().pushState(new TestState("main_test"));
    stateManager().setActiveState("main_test");
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}