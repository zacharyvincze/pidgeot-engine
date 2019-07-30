# Pidgeot Engine

An in-development, SDL2 based, 2D game engine written in C++.

## Compiling From Source

Install the required dependencies:

`sudo apt-get install libsdl2-dev libsdl2-image-dev`

Compile using cmake:

`mkdir _build && cd _build && cmake .. && make`

## Running the Engine

Currently, the program must be executed from the project's root.

`_build/./PidgeotEngine`

## Features

The engine is relatively early in development and being used as a method of learning engine creation using C++ and SDL2.  The current feature set is quite bare and typical of most other engines.

- Animated sprites
- Resource management
- Basic camera controls
- Game state management and task based operations
- Entity management
- Axis-aligned entity collision detection

## What's with the name?

Pidgeot's been a favourite since Yellow.  Plus, I'm not that great at naming things.
