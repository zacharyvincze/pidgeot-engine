#pragma once

#include <vector>
#include <map>
#include "modules/gamestate.h"

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