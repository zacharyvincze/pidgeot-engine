#include "engine.h"

#include <SDL2/SDL_image.h>
#include "spdlog/spdlog.h"

namespace Pidgeot {
    Engine* Engine::mInstance = nullptr;

    Engine::~Engine() {
        // Deallocate engine pointer
        // delete minstance;
        delete mInstance;
    }

    Engine::Engine() {
        spdlog::set_level(spdlog::level::debug);
        spdlog::info("Initializing PidgeotEngine");

        // Init SDL subsystems
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);

        // Read configuration file
        m_config = std::unique_ptr<Config>(new Config("resources/pidgeot_engine.conf"));
        int window_width = m_config->getNumOption("width");
        int window_height = m_config->getNumOption("height");
        uint32_t window_mode;
        if (m_config->getBoolOption("fullscreen")) window_mode = SDL_WINDOW_FULLSCREEN_DESKTOP;
        else window_mode = SDL_WINDOW_SHOWN;
        std::string window_title = m_config->getOption("title");

        // Create required objects
        m_window = std::shared_ptr<Window>(new Window(window_title.c_str(), window_width, window_height, window_mode));
        m_renderer = std::shared_ptr<Renderer>(new Renderer(m_window, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
        m_resource_manager = std::shared_ptr<ResourceManager>(new ResourceManager(m_renderer));
        m_input = std::shared_ptr<Input>(new Input);
        m_state_manager = std::shared_ptr<StateManager>(new StateManager());

        // Allocate memory for singleton pointer
        mInstance = this;

        // Set engine loop flag to true and start running the engine
        mRunning = true;

        // Start engine clock
        m_timer.reset();

        spdlog::info("Successfully initialized PidgeotEngine");
    }

    void Engine::run() {
        while (mRunning) {
            m_state_manager->update();
        }
    }
    
}