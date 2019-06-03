#include "application.h"

#include "tasks/tasks.h"
#include "modules/gamestate.h"

Application::Application() {
    std::shared_ptr<GameState> main_state = std::shared_ptr<GameState>(new GameState("main"));
    main_state->pushTask(new TaskStart);
    main_state->pushTask(new TaskDraw);
    main_state->pushTask(new TaskEnd);
    setGameState(main_state);
}

Application::~Application() {

}

Pidgeot::Engine* Pidgeot::createApplication() {
    return new Application();
}