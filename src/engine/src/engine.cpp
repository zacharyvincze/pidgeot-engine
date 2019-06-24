#include "engine.h"

#include <SDL2/SDL_image.h>
#include "log.h"

#include <chrono>
#include <thread>

namespace Pidgeot {
    Engine* Engine::mInstance = nullptr;

    Engine::~Engine() {
        // Deallocate engine pointer
        // delete minstance;
        delete mInstance;
    }

    Config& Engine::getConfig() {
        if (m_config == nullptr) m_config = std::shared_ptr<Config>(new Config("resources/pidgeot_engine.conf"));
        return *m_config;
    }

    Renderer& Engine::getRenderer() {
        if (m_renderer == nullptr) m_renderer = std::shared_ptr<Renderer>(new Renderer(SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
        return *m_renderer;
    }

    Window& Engine::getWindow() {
        if (m_window == nullptr) m_window = std::shared_ptr<Window>(new Window("Testing", 640, 320, SDL_WINDOW_SHOWN));
        return *m_window;
    }

    Input& Engine::getInput() {
        if (m_input == nullptr) m_input = std::shared_ptr<Input>(new Input());
        return *m_input;
    }

    ResourceManager& Engine::getResourceManager() {
        if (m_resource_manager == nullptr) m_resource_manager = std::shared_ptr<ResourceManager>(new ResourceManager());
        return *m_resource_manager;
    }

    StateManager& Engine::getStateManager() {
        if (m_state_manager == nullptr) m_state_manager = std::shared_ptr<StateManager>(new StateManager());
        return *m_state_manager;
    }

    CameraManager& Engine::getCameraManager() {
        if (m_camera_manager == nullptr) m_camera_manager = std::shared_ptr<CameraManager>(new CameraManager());
        return *m_camera_manager;
    }

    Timer& Engine::getTimer() {
        if (m_timer == nullptr) m_timer = std::shared_ptr<Timer>(new Timer());
        return *m_timer;
    }

    Pidgeot::

    Engine::Engine() {
        Pidgeot::Log::init();
        ENGINE_INFO("Initializing PidgeotEngine");
        m_frames_per_second = getConfig().getNumOption("fps");

        // Init SDL subsystems
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);

        // Frames per second
        // m_frames_per_second = m_config->getNumOption("fps");

        // Allocate memory for singleton pointer
        mInstance = this;

        // Set engine loop flag to true and start running the engine
        mRunning = true;

        // Start engine clock
        getTimer().reset();

        ENGINE_INFO("Successfully initialized PidgeotEngine");
    }

    void Engine::run() {
        while (mRunning) {
            int start_time = getTimer().ticks();
            getStateManager().update();
            int elapsed_time = getTimer().ticks() - start_time;
            if (1000/m_frames_per_second > elapsed_time) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000/m_frames_per_second-elapsed_time));
            }
        }
    }
    
}