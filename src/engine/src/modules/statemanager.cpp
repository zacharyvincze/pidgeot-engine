#include "modules/statemanager.h"

void StateManager::update() {
    for (std::map<std::string, GameState*>::iterator i = m_gamestates.begin(); i != m_gamestates.end(); i++) {
        i->second->update();
    }
}