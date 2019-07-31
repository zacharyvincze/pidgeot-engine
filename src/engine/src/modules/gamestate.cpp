#include "modules/gamestate.h"

#include "log.h"

namespace Pidgeot {
GameState::GameState(const std::string id)
    : m_id(id)
{
    ENGINE_DEBUG("Created GameState {}", m_id.c_str());
}

void GameState::onUpdate()
{
    for (Pidgeot::Task* task : m_tasks) {
        task->onUpdate();
    }
}

void GameState::onRender()
{
    for (Pidgeot::Task* task : m_tasks) {
        task->onRender();
    }
}

GameState::~GameState()
{
    for (Pidgeot::Task* task : m_tasks) {
        delete task;
    }
}
}