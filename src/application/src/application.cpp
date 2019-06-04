#include "application.h"

#include "states/test.h"

Application::Application() {
    pushState(new TestState("main_test"));
    setActiveState("main_test");
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}