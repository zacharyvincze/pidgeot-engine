#include "modules/statemanager.h"

#include <stdexcept>
#include "log.h"

namespace Pidgeot {
    StateManager::~StateManager() {
        for (std::map<std::string, GameState*>::iterator i = m_gamestates.begin(); i != m_gamestates.end(); i++) {
            delete i->second;
        }
    }

    void StateManager::onUpdate() {
        for (std::map<std::string, GameState*>::iterator i = m_gamestates.begin(); i != m_gamestates.end(); i++) {
            i->second->onUpdate();
        }
    }

    void StateManager::onRender() {
        for (std::map<std::string, GameState*>::iterator i = m_gamestates.begin(); i != m_gamestates.end(); i++) {
            i->second->onRender();
        }
    }

    void StateManager::pushState(GameState* state) {
        m_gamestates.insert(std::pair<std::string, GameState*>(state->getID(), state));
        ENGINE_DEBUG("Pushed Gamestate: {}", state->getID());
    }

    void StateManager::setActiveState(const std::string id) {
        try {
            m_active_state = m_gamestates.at(id);
        } catch (std::out_of_range &e) {
            ENGINE_ERROR("Gamestate {} does not exist: {}", id.c_str(), e.what());
            exit(-1);
        }
        ENGINE_DEBUG("Set active state: {}", id);
    }

    GameState& StateManager::getState(const std::string id) {
        try {
            return *m_gamestates.at(id);
        } catch (std::out_of_range &e) {
            ENGINE_ERROR("GameState {} does not exist: {}", id.c_str(), e.what());
            exit(-1);
        }
    }
}