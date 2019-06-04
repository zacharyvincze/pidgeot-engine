#include "states/test.h"

#include "tasks/tasks.h"

TestState::TestState(const std::string name) : GameState(name) {
    pushTask(new TaskStart);
    pushTask(new TaskDraw);
    pushTask(new TaskEnd);
}