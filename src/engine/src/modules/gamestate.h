#pragma once

#include "task.h"
#include <vector>
#include <string>

class GameState {
    public:
        GameState(const std::string name);
        ~GameState();
        void update();
        void cleanup();

        inline void pushTask(Pidgeot::Task* task) { m_tasks.push_back(task); }
        inline void pullTask() { m_tasks.pop_back(); }
    private:
        std::vector<Pidgeot::Task*> m_tasks;
        std::string name;
};