#pragma once

#include <SDL2/SDL.h>
#include <map>

namespace Pidgeot {
    class Input {
        public:
            bool wasKeyPressed(SDL_Scancode key);
            bool wasKeyReleased(SDL_Scancode key);
            bool wasKeyHeld(SDL_Scancode key);

            void reset();
            void pollEvents();
        private:
            SDL_Event s_event;
            std::map<SDL_Scancode, bool> s_held_keys;
            std::map<SDL_Scancode, bool> s_pressed_keys;
            std::map<SDL_Scancode, bool> s_released_keys;

            void keyDownEvent(SDL_Scancode key);
            void keyUpEvent(SDL_Scancode key);
    };
}