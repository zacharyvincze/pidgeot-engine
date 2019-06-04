#pragma once

#include <vector>
#include <map>
#include "modules/gamestate.h"

class StateManager {
    public:
        inline void pushState(GameState* state) { m_gamestates.insert(std::pair<std::string, GameState*>(state->getName(), state)); }
        inline void setActiveState(const std::string name) { m_active_state = m_gamestates.at(name); }

        void update();
    private:
        std::map<std::string, GameState*> m_gamestates;
        GameState* m_active_state;
};