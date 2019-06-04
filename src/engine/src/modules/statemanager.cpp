#include "modules/statemanager.h"

#include <stdexcept>
#include "spdlog/spdlog.h"

void StateManager::update() {
    for (std::map<std::string, GameState*>::iterator i = m_gamestates.begin(); i != m_gamestates.end(); i++) {
        i->second->update();
    }
}

void StateManager::pushState(GameState* state) {
    m_gamestates.insert(std::pair<std::string, GameState*>(state->getName(), state));
    spdlog::debug("Pushed Gamestate: {}", state->getName());
}

void StateManager::setActiveState(const std::string name) {
    try {
        m_active_state = m_gamestates.at(name);
    } catch (std::out_of_range &e) {
        spdlog::error("Gamestate {} does not exist: {}", name.c_str(), e.what());
        exit(-1);
    }
    spdlog::debug("Set active state: {}", name);
}