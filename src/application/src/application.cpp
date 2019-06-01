#include "application.h"

#include "tasks/tasks.h"

Application::Application() {
    // Quickly load resources and things like that I suppose

    pushTask(new TaskStart);
    pushTask(new TaskDraw);
    pushTask(new TaskEnd);
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}