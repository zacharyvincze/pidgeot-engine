#pragma once

#include "modules/gamestate.h"
#include <map>
#include <vector>

namespace Pidgeot {
class StateManager {
public:
    ~StateManager();

    void pushState(GameState* state);
    void setActiveState(const std::string id);

    GameState& getState(const std::string id);

    void onUpdate();
    void onRender();

private:
    std::map<std::string, GameState*> m_gamestates;
    GameState* m_active_state;
};
}