#pragma once

#include <vector>
#include <map>
#include "modules/gamestate.h"

namespace Pidgeot {
    class StateManager {
        public:
            void pushState(GameState* state);
            void setActiveState(const std::string name);

            void update();
        private:
            std::map<std::string, GameState*> m_gamestates;
            GameState* m_active_state;
    };
}