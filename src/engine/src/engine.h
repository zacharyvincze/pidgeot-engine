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

            Pidgeot::Renderer& getRenderer();
            Pidgeot::Window& getWindow();
            Pidgeot::ResourceManager& getResourceManager();
            Pidgeot::CameraManager& getCameraManager();
            Pidgeot::StateManager& getStateManager();
            Pidgeot::Config& getConfig();
            Pidgeot::Timer& getTimer();
            Pidgeot::Input& getInput();

            inline long getTicks() { return getTimer().ticks(); }

            inline void quit() { mRunning = false; }
        private:
            static Engine* mInstance;

            std::shared_ptr<Pidgeot::Renderer> m_renderer;
            std::shared_ptr<Pidgeot::Window> m_window;
            std::shared_ptr<Pidgeot::ResourceManager> m_resource_manager;
            std::shared_ptr<Pidgeot::Input> m_input;
            std::shared_ptr<Pidgeot::StateManager> m_state_manager;
            std::shared_ptr<Pidgeot::CameraManager> m_camera_manager;
            std::shared_ptr<Pidgeot::Timer> m_timer;
            std::shared_ptr<Pidgeot::Config> m_config;

            // Main flag for running engine loop
            bool mRunning;

            uint m_frames_per_second;
            uint m_window_width, m_window_height;
            uint32_t m_video_flags, m_window_flags;
            std::string m_window_title;
    };

    Engine* createApplication();
}