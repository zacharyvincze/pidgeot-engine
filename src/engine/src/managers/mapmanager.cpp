#include "mapmanager.h"

#include <stdexcept>

namespace Pidgeot {
void MapManager::loadMap(Map* map)
{
    ENGINE_INFO("Loading map: {}", map->getName());
    if (m_maps.count(map->getName()) <= 0) {
        m_maps[map->getName()] = map;
    } else {
        ENGINE_WARN("Map has already been loaded: {}", map->getName());
    }
}

void MapManager::setMap(const std::string name)
{
    try {
        m_currentMap = m_maps[name];
    } catch (std::out_of_range error) {
        ENGINE_ERROR("Error when trying to set map, not loaded: {}", name.c_str());
        exit(1);
    }
    ENGINE_INFO("Set map: {}", name.c_str());
}

void MapManager::onRender()
{
    if (m_currentMap != nullptr)
        m_currentMap->onRender();
}

void MapManager::onUpdate()
{
    if (m_currentMap != nullptr)
        m_currentMap->onUpdate();
}

MapManager::~MapManager()
{
    for (std::unordered_map<std::string, Map*>::iterator i = m_maps.begin(); i != m_maps.end(); i++) {
        delete i->second;
        ENGINE_INFO("Removed map: %s", i->second->getName());
    }
    delete m_currentMap;
}
}