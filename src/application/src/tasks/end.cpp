#include "tasks/end.h"

void TaskEnd::update() {
    Pidgeot::Engine::get().renderer().present();
}