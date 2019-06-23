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

    Engine::Engine() :
        m_config("resources/pidgeot_engine.conf") {
        Pidgeot::Log::init();
        ENGINE_INFO("Initializing PidgeotEngine");

        // Init SDL subsystems
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);

        // Read configuration file
        m_window_width = m_config.getNumOption("width");
        m_window_height = m_config.getNumOption("height");
        uint32_t window_mode;
        if (m_config.getBoolOption("fullscreen")) window_mode = SDL_WINDOW_FULLSCREEN_DESKTOP;
        else window_mode = SDL_WINDOW_SHOWN;
        std::string window_title = m_config.getOption("title");

        // Renderer options
        uint32_t renderer_flags = 0;
        if (m_config.getBoolOption("enable_vsync")) renderer_flags |= SDL_RENDERER_PRESENTVSYNC;
        if (m_config.getBoolOption("renderer_accelerated")) renderer_flags |= SDL_RENDERER_ACCELERATED;

        // Frames per second
        m_frames_per_second = m_config.getNumOption("fps");

        // Initialize non-default constructor objects
        m_window = std::shared_ptr<Pidgeot::Window>(new Pidgeot::Window(window_title, m_window_width, m_window_height, window_mode));
        m_renderer = std::shared_ptr<Pidgeot::Renderer>(new Pidgeot::Renderer(*m_window, renderer_flags));
        m_resource_manager = std::shared_ptr<Pidgeot::ResourceManager>(new Pidgeot::ResourceManager(*m_renderer));

        // Allocate memory for singleton pointer
        mInstance = this;

        // Set engine loop flag to true and start running the engine
        mRunning = true;

        // Start engine clock
        m_timer.reset();

        ENGINE_INFO("Successfully initialized PidgeotEngine");
    }

    void Engine::run() {
        while (mRunning) {
            int start_time = getTicks();
            m_state_manager.update();
            int elapsed_time = getTicks() - start_time;
            if (1000/m_frames_per_second > elapsed_time) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000/m_frames_per_second-elapsed_time));
            }
        }
    }
    
}