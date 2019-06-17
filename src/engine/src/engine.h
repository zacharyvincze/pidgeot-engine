#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "spdlog/spdlog.h"

#include "modules/renderer.h"
#include "modules/input.h"
#include "modules/timer.h"
#include "modules/config.h"
#include "modules/statemanager.h"

#include "modules/resources/resourcemanager.h"
#include "modules/resources/text.h"

namespace Pidgeot {
    class Engine {
        public:
            inline static Engine& get() { return *mInstance; }
            Engine();
            ~Engine();

            void run();

            inline Renderer& renderer() { return *m_renderer; }
            inline Window& window() { return *m_window; }
            inline ResourceManager& resources() { return *m_resource_manager; }
            inline Input& input() { return *m_input; }
            inline StateManager& stateManager() { return *m_state_manager; }

            inline long getTicks() { return m_timer.ticks(); }

            inline void quit() { mRunning = false; }
        private:
            static Engine* mInstance;
            
            Timer m_timer;

            std::shared_ptr<Renderer> m_renderer;
            std::shared_ptr<Window> m_window;
            std::shared_ptr<ResourceManager> m_resource_manager;
            std::shared_ptr<Input> m_input;
            std::shared_ptr<StateManager> m_state_manager;
            
            std::unique_ptr<Config> m_config;

            // Main flag for running engine loop
            bool mRunning;

            uint m_frames_per_second;
    };

    Engine* createApplication();
}