#pragma once

#include "task.h"
#include <string>
#include <vector>

#include "utils/log.h"

namespace Pidgeot {
class GameState {
public:
    GameState(const std::string name);
    ~GameState();

    void onUpdate();
    void onRender();

    inline std::string getID() { return m_id; }

    inline void pushTask(Pidgeot::Task* task)
    {
        m_tasks.push_back(task);
        ENGINE_DEBUG("Pushed task {:p} to state {}", (void*)task, m_id);
    }
    inline void pullTask() { m_tasks.pop_back(); }

private:
    std::vector<Pidgeot::Task*> m_tasks;
    std::string m_id;
};
}