#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "spdlog/spdlog.h"

#include "modules/renderer.h"
#include "modules/input.h"
#include "modules/timer.h"
#include "modules/config.h"
#include "modules/statemanager.h"
#include "modules/cameramanager.h"

#include "modules/resources/resourcemanager.h"

namespace Pidgeot {
    class Engine {
        public:
            inline static Engine& get() { return *mInstance; }
            Engine();
            ~Engine();

            void run();

            inline uint getWindowWidth() { return m_window_width; }
            inline uint getWindowHeight() { return m_window_height; }

            inline long getTicks() { return m_timer.ticks(); }

            inline void quit() { mRunning = false; }
        private:
            static Engine* mInstance;

            // Main flag for running engine loop
            bool mRunning;

            uint m_frames_per_second;
            uint m_window_width, m_window_height;
            
        protected:
            Pidgeot::Timer m_timer;
            Pidgeot::Input m_input;
            Pidgeot::StateManager m_state_manager;
            Pidgeot::CameraManager m_camera_manager;
            Pidgeot::Config m_config;

            std::shared_ptr<Pidgeot::Window> m_window;
            std::shared_ptr<Pidgeot::Renderer> m_renderer;
            std::shared_ptr<Pidgeot::ResourceManager> m_resource_manager;
    };

    Engine* createApplication();
}