#include "application.h"

#include "states/states.h"

Application::Application() {
    APP_INFO("Initializing application");
    m_state_manager.pushState(new TestState("main_test", *m_renderer, *m_resource_manager, m_camera_manager, m_input, m_config));
    m_state_manager.setActiveState("main_test");

    m_camera_manager.pushCamera(new Pidgeot::Camera("main", 0,0,getWindowWidth(), getWindowHeight()));
    m_camera_manager.setActiveCamera("main");
    APP_INFO("Successfully initialized application");
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}