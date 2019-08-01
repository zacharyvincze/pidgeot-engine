#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <vector>

#include "engine.h"

#include "modules/map/tile.h"
#include "resources/texture.h"

#include "core/renderer.h"
#include "managers/cameramanager.h"
#include "managers/resourcemanager.h"

namespace Pidgeot {
class Tileset {
public:
    Tileset(const std::string filepath, const int tile_size);
    void renderTile(Tile* tile);

private:
    std::vector<SDL_Rect> m_tileRects;
    Texture* m_tilesetTexture;

    int m_tileSize;

    ResourceManager& m_resourceManager;
    CameraManager& m_cameraManager;
    Renderer& m_renderer;
};
}