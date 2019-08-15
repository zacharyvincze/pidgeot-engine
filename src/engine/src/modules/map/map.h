#pragma once

#include "core/renderer.h"
#include "managers/cameramanager.h"
#include "managers/resourcemanager.h"
#include "modules/map/tile.h"
#include "modules/map/tileset.h"

namespace Pidgeot {
class Map {
public:
    Map(int x, int y, const std::string tilemap, const std::string tileset);
    ~Map();

    void onRender();
    void onUpdate();

    std::string getName() { return m_name; }

private:
    std::vector<Pidgeot::Tile*> m_tilemap;
    SDL_Rect m_position;

    std::string m_name;

    unsigned int m_tileWidth, m_tileHeight;

    std::shared_ptr<Tileset> m_tileset;

    Pidgeot::Renderer& m_renderer;
    Pidgeot::ResourceManager& m_resourceManager;
    Pidgeot::CameraManager& m_cameraManager;
};
}