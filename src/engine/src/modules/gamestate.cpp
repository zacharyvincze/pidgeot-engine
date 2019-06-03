#include "modules/gamestate.h"

#include "spdlog/spdlog.h"

GameState::GameState(const std::string name) : name(name) {
    spdlog::info("Created GameState {}", name.c_str());
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