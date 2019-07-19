#pragma once

#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "engine.h"

#include "modules/resources/map/tile.h"
#include "modules/resources/texture.h"

#include "modules/renderer.h"
#include "modules/cameramanager.h"
#include "modules/resources/resourcemanager.h"

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