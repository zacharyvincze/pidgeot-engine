#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include "modules/map/map.h"
#include <string>
#include <unordered_map>

namespace Pidgeot {
class MapManager {
public:
    ~MapManager();

    void loadMap(Pidgeot::Map* map);
    void setMap(const std::string name);
    Map* getCurrentMap() { return m_currentMap; }

    void onRender();
    void onUpdate();

private:
    std::unordered_map<std::string, Pidgeot::Map*> m_maps;
    Pidgeot::Map* m_currentMap;
};
}

#endif // MAP_MANAGER_H