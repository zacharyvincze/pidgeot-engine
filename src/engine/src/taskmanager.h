#pragma once

#include <vector>
#include <memory>
#include "task.h"

#include "spdlog/spdlog.h"

class TaskManager {
    public:
        void test();
        void addTask(Pidgeot::Task* task) { mTasks.push_back(task); }
        void popTask() { mTasks.pop_back(); }

        inline std::vector<Pidgeot::Task*>::iterator begin() { return mTasks.begin(); }
        inline std::vector<Pidgeot::Task*>::iterator end() { return mTasks.end(); }
    private:
        std::vector<Pidgeot::Task*> mTasks;
};