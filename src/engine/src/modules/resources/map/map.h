#pragma once

#include "engine.h"
#include "modules/resources/map/tile.h"

namespace Pidgeot {
    class Map {
        public:
            Map(int x, int y, const std::string tilemap, const std::string tileset);
            ~Map();

            void onRender();
            void onUpdate();
        private:
            std::vector<Pidgeot::Tile*> m_tilemap;
            SDL_Rect m_position;

            unsigned int m_tileWidth, m_tileHeight;

            Pidgeot::Texture* m_tileset;

            Pidgeot::Renderer& m_renderer;
            Pidgeot::ResourceManager& m_resourceManager;
            Pidgeot::CameraManager& m_cameraManager;
    };
}