#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "core/config.h"
#include "core/input.h"
#include "core/renderer.h"
#include "core/timer.h"
#include "managers/cameramanager.h"
#include "managers/entitymanager.h"
#include "managers/resourcemanager.h"
#include "managers/statemanager.h"
#include "utils/log.h"

namespace Pidgeot {
class Engine {
public:
    inline static Engine& get() { return *s_instance; }
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
    Pidgeot::EntityManager& getEntityManager();

    inline long getTicks() { return getTimer().ticks(); }

    void quit();

private:
    static Engine* s_instance;

    std::shared_ptr<Pidgeot::Renderer> m_renderer;
    std::shared_ptr<Pidgeot::Window> m_window;
    std::shared_ptr<Pidgeot::ResourceManager> m_resource_manager;
    std::shared_ptr<Pidgeot::Input> m_input;
    std::shared_ptr<Pidgeot::StateManager> m_state_manager;
    std::shared_ptr<Pidgeot::CameraManager> m_camera_manager;
    std::shared_ptr<Pidgeot::Timer> m_timer;
    std::shared_ptr<Pidgeot::Config> m_config;
    std::shared_ptr<Pidgeot::EntityManager> m_entityManager;

    // Main flag for running engine loop
    bool m_running;

    uint m_frames_per_second;
    uint m_window_width, m_window_height;
    uint32_t m_video_flags, m_window_flags;
    std::string m_window_title;
};

Engine* createApplication();
} // namespace Pidgeot
