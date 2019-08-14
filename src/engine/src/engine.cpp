#include "engine.h"

#include "utils/log.h"
#include <SDL2/SDL_image.h>

#include "GL/gl3w.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

#include <chrono>
#include <thread>

namespace Pidgeot {
Engine* Engine::s_instance = nullptr;

Engine::~Engine()
{
    // Deallocate engine pointer
    // delete minstance;
    delete s_instance;
}

Config& Engine::getConfig()
{
    if (m_config == nullptr)
        m_config.reset(new Config("resources/pidgeot_engine.conf"));
    return *m_config;
}

Renderer& Engine::getRenderer()
{
    if (m_renderer == nullptr)
        m_renderer.reset(new Renderer(m_video_flags));
    return *m_renderer;
}

Window& Engine::getWindow()
{
    if (m_window == nullptr)
        m_window.reset(new Window(m_window_title, m_window_width, m_window_height,
            m_window_flags));
    return *m_window;
}

Input& Engine::getInput()
{
    if (m_input == nullptr)
        m_input.reset(new Input());
    return *m_input;
}

ResourceManager& Engine::getResourceManager()
{
    if (m_resource_manager == nullptr)
        m_resource_manager.reset(new ResourceManager());
    return *m_resource_manager;
}

StateManager& Engine::getStateManager()
{
    if (m_state_manager == nullptr)
        m_state_manager.reset(new StateManager());
    return *m_state_manager;
}

CameraManager& Engine::getCameraManager()
{
    if (m_camera_manager == nullptr)
        m_camera_manager.reset(new CameraManager());
    return *m_camera_manager;
}

Timer& Engine::getTimer()
{
    if (m_timer == nullptr)
        m_timer.reset(new Timer());
    return *m_timer;
}

EntityManager& Engine::getEntityManager()
{
    if (m_entityManager == nullptr)
        m_entityManager.reset(new EntityManager());
    return *m_entityManager;
}

void Engine::initialize()
{
    // Read configuration
    m_frames_per_second = getConfig().getNumOption("fps");
    m_window_width = getConfig().getNumOption("width");
    m_window_height = getConfig().getNumOption("height");
    if (getConfig().getBoolOption("enable_vsync"))
        m_video_flags |= SDL_RENDERER_PRESENTVSYNC;
    if (getConfig().getBoolOption("renderer_accelerated"))
        m_video_flags |= SDL_RENDERER_ACCELERATED;
    if (getConfig().getBoolOption("fullscreen"))
        m_window_flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
    else
        m_window_flags = SDL_WINDOW_SHOWN;
    m_window_title = getConfig().getOption("title");

    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        ENGINE_ERROR("Unable to initialize SDL: %s", SDL_GetError());
    }
    IMG_Init(IMG_INIT_PNG);

    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GLContext gl_context = SDL_GL_CreateContext(getWindow().getWindow());
    SDL_GL_MakeCurrent(getWindow().getWindow(), gl_context);

    // Initialize gl3w loader
    gl3wInit();

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    // Setup platform/renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(getWindow().getWindow(), gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

Engine::Engine()
{
    Pidgeot::Log::init();
    ENGINE_INFO("Initializing PidgeotEngine");
    initialize();

    s_instance = this;
    m_running = true;

    getTimer().reset();

    ENGINE_INFO("Successfully initialized PidgeotEngine");
}

void Engine::run()
{
    while (m_running) {
        int start_time = getTimer().ticks();

        getInput().reset();
        getInput().pollEvents();

        // ImGui frame creation
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(getWindow().getWindow());
        ImGui::NewFrame();

        // Simple statistics window for displaying framerate
        ImGui::Begin("Statistics");
        ImGui::TextWrapped("Average Framerate: %1.f", ImGui::GetIO().Framerate);
        ImGui::Spacing();
        ImGui::TextWrapped("Entity Count: %i", getEntityManager().getEntityCount());
        ImGui::End();

        ImGui::Render();
        getRenderer().setDrawColor(0, 0, 0, 1);
        getRenderer().clear();

        // Update current state and all entities
        getStateManager().onUpdate();
        getEntityManager().onUpdate();

        // Render current state and all entities, draw graphics in buffer
        getStateManager().onRender();
        getEntityManager().onRender();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        getRenderer().present();

        // Limit frames per second
        int elapsed_time = getTimer().ticks() - start_time;
        if (1000 / m_frames_per_second > elapsed_time) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(1000 / m_frames_per_second - elapsed_time));
        }
    }
}

void Engine::quit()
{
    ENGINE_INFO("Quitting PidgeotEngine");
    m_running = false;
    SDL_Quit();
    IMG_Quit();
    ENGINE_INFO("Successfully quit PidgeotEngine");
}
}