#include "modules/map/tileset.h"

namespace Pidgeot {
Tileset::Tileset(const std::string filepath, int tile_size)
    : m_renderer(Engine::get().getRenderer())
    , m_resourceManager(Engine::get().getResourceManager())
    , m_cameraManager(Engine::get().getCameraManager())
    , m_tileSize(tile_size)
{
    m_tilesetTexture = m_resourceManager.get<Pidgeot::Texture>(filepath);

    for (int y = 0; y < m_tilesetTexture->getHeight() / m_tileSize; y++) {
        for (int x = 0; x < m_tilesetTexture->getWidth() / m_tileSize; x++) {
            m_tileRects.push_back({ x * m_tileSize, y * m_tileSize, m_tileSize, m_tileSize });
        }
    }
}

void Tileset::renderTile(Tile* tile)
{
    SDL_Rect destination_rect = { tile->x, tile->y, m_tileSize, m_tileSize };
    m_renderer.drawTexture(m_tilesetTexture, &m_tileRects[tile->id], &destination_rect);
}
}