#include "modules/gamestate.h"

#include "spdlog/spdlog.h"

GameState::GameState(const std::string name) : m_name(name) {
    spdlog::debug("Created GameState {}", m_name.c_str());
}

void GameState::update() {
    for (Pidgeot::Task* task : m_tasks) {
        task->update();
    }
}

GameState::~GameState() {
    cleanup();
}

void GameState::cleanup() {
    for (Pidgeot::Task* task : m_tasks) {
        delete task;
    }
}