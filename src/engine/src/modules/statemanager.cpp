#include "modules/statemanager.h"

#include <stdexcept>
#include "log.h"

void StateManager::update() {
    for (std::map<std::string, GameState*>::iterator i = m_gamestates.begin(); i != m_gamestates.end(); i++) {
        i->second->update();
    }
}

void StateManager::pushState(GameState* state) {
    m_gamestates.insert(std::pair<std::string, GameState*>(state->getName(), state));
    ENGINE_DEBUG("Pushed Gamestate: {}", state->getName());
}

void StateManager::setActiveState(const std::string name) {
    try {
        m_active_state = m_gamestates.at(name);
    } catch (std::out_of_range &e) {
        ENGINE_ERROR("Gamestate {} does not exist: {}", name.c_str(), e.what());
        exit(-1);
    }
    ENGINE_DEBUG("Set active state: {}", name);
}