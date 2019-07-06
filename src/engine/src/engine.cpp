#include "engine.h"

#include <SDL2/SDL_image.h>
#include "log.h"

#include <chrono>
#include <thread>

namespace Pidgeot {
    Engine* Engine::s_instance = nullptr;

    Engine::~Engine() {
        // Deallocate engine pointer
        // delete minstance;
        delete s_instance;
    }

    Config& Engine::getConfig() {
        if (m_config == nullptr) m_config.reset(new Config("resources/pidgeot_engine.conf"));
        return *m_config;
    }

    Renderer& Engine::getRenderer() {
        if (m_renderer == nullptr) m_renderer.reset(new Renderer(m_video_flags));
        return *m_renderer;
    }

    Window& Engine::getWindow() {
        if (m_window == nullptr) m_window.reset(new Window(m_window_title, m_window_width, m_window_height, m_window_flags));
        return *m_window;
    }

    Input& Engine::getInput() {
        if (m_input == nullptr) m_input.reset(new Input());
        return *m_input;
    }

    ResourceManager& Engine::getResourceManager() {
        if (m_resource_manager == nullptr) m_resource_manager.reset(new ResourceManager());
        return *m_resource_manager;
    }

    StateManager& Engine::getStateManager() {
        if (m_state_manager == nullptr) m_state_manager.reset(new StateManager());
        return *m_state_manager;
    }

    CameraManager& Engine::getCameraManager() {
        if (m_camera_manager == nullptr) m_camera_manager.reset(new CameraManager());
        return *m_camera_manager;
    }

    Timer& Engine::getTimer() {
        if (m_timer == nullptr) m_timer.reset(new Timer());
        return *m_timer;
    }

    EntityManager& Engine::getEntityManager() {
        if (m_entityManager == nullptr) m_entityManager.reset(new EntityManager());
        return *m_entityManager;
    }

    Engine::Engine() {
        Pidgeot::Log::init();
        ENGINE_INFO("Initializing PidgeotEngine");

        // Read configuration
        m_frames_per_second = getConfig().getNumOption("fps");
        m_window_width = getConfig().getNumOption("width");
        m_window_height = getConfig().getNumOption("height");
        if (getConfig().getBoolOption("enable_vsync")) m_video_flags |= SDL_RENDERER_PRESENTVSYNC;
        if (getConfig().getBoolOption("renderer_accelerated")) m_video_flags |= SDL_RENDERER_ACCELERATED;
        if (getConfig().getBoolOption("fullscreen")) m_window_flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
        else m_window_flags = SDL_WINDOW_SHOWN;
        m_window_title = getConfig().getOption("title");

        // Init SDL subsystems
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);

        s_instance = this;
        m_running = true;

        getTimer().reset();

        ENGINE_INFO("Successfully initialized PidgeotEngine");
    }

    void Engine::run() {
        while (m_running) {
            int start_time = getTimer().ticks();

            getInput().reset();
            getInput().pollEvents();

            getStateManager().onUpdate();
            getStateManager().onRender();

            // Limit frames per second
            int elapsed_time = getTimer().ticks() - start_time;
            if (1000/m_frames_per_second > elapsed_time) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000/m_frames_per_second-elapsed_time));
            }
        }
    }

    void Engine::quit() {
        ENGINE_INFO("Quitting PidgeotEngine");
        m_running = false;
        SDL_Quit();
        IMG_Quit();
        ENGINE_INFO("Successfully quit PidgeotEngine");
    }
}