#include "core/input.h"

#include "spdlog/spdlog.h"

namespace Pidgeot {
void Input::pollEvents()
{
    while (SDL_PollEvent(&s_event)) {
        if (s_event.type == SDL_KEYDOWN)
            keyDownEvent(s_event.key.keysym.scancode);
        else if (s_event.type == SDL_KEYUP)
            keyUpEvent(s_event.key.keysym.scancode);
    }
}

void Input::reset()
{
    s_pressed_keys.clear();
    s_released_keys.clear();
}

void Input::keyDownEvent(SDL_Scancode key)
{
    s_pressed_keys[key] = true;
    s_held_keys[key] = true;
}

void Input::keyUpEvent(SDL_Scancode key)
{
    s_released_keys[key] = true;
    s_held_keys[key] = false;
}

bool Input::wasKeyHeld(SDL_Scancode key)
{
    return s_held_keys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
    return s_released_keys[key];
}

bool Input::wasKeyPressed(SDL_Scancode key)
{
    return s_pressed_keys[key];
}
}