#pragma once

namespace Pidgeot {
    struct Tile {
        Tile(unsigned int id, int x, int y) : id(id), x(x), y(y) {}
        unsigned int id;
        int x, y;
    };
}