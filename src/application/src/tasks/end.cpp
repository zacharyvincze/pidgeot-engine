#include "tasks/end.h"

void TaskEnd::update() {
    Pidgeot::Engine::get().getRenderer().present();
}