#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "taskmanager.h"

#include "modules/renderer.h"
#include "modules/input.h"
#include "modules/resourcemanager.h"
#include "modules/timer.h"
#include "modules/config.h"

namespace Pidgeot {
    class Engine {
        public:
            inline static Engine& get() { return *mInstance; }
            Engine();
            ~Engine();

            void run();

            inline void pushTask(Task* task) { m_task_manager.addTask(task); }

            inline Renderer& renderer() { return *m_renderer; }
            inline Window& window() { return *m_window; }
            inline ResourceManager& resources() { return *m_resource_manager; }
            inline Input& input() { return *m_input; }

            inline long getTicks() { return m_timer.ticks(); }

            inline void quit() { mRunning = false; }
        private:
            static Engine* mInstance;

            TaskManager m_task_manager;
            Timer m_timer;

            std::shared_ptr<Renderer> m_renderer;
            std::shared_ptr<Window> m_window;
            std::shared_ptr<ResourceManager> m_resource_manager;
            std::shared_ptr<Input> m_input;
            
            std::unique_ptr<Config> m_config;

            // Main flag for running engine loop
            bool mRunning;
    };

    Engine* createApplication();
}