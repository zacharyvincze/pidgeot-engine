#include "modules/resources/map/map.h"

#include "rapidxml/rapidxml.hpp"
#include <fstream>
#include <sstream>

namespace Pidgeot {
Map::Map(int x, int y, const std::string tilemap, const std::string tileset)
    : m_position({ x, y, 0, 0 })
    , m_renderer(Pidgeot::Engine::get().getRenderer())
    , m_resourceManager(Pidgeot::Engine::get().getResourceManager())
    , m_cameraManager(Pidgeot::Engine::get().getCameraManager())
{
    // Read tilemap
    std::ostringstream sstream;
    std::ifstream infile(tilemap.c_str());
    sstream << infile.rdbuf();
    infile.close();
    std::string content(sstream.str());

    rapidxml::xml_document<> doc;
    doc.parse<0>(&content[0]);
    rapidxml::xml_node<>* root_node = doc.first_node("map");

    m_position.w = atoi(root_node->first_attribute("width")->value());
    m_position.h = atoi(root_node->first_attribute("height")->value());

    m_tileWidth = atoi(root_node->first_attribute("tilewidth")->value());
    m_tileHeight = atoi(root_node->first_attribute("tileheight")->value());

    rapidxml::xml_node<>* data_node = root_node->first_node("layer")->first_node("data");
    std::string layer_data = data_node->value();

    // Separate CSV data
    std::stringstream ss(layer_data);
    std::vector<std::string> string_data;
    while (ss.good()) {
        std::string substring;
        std::getline(ss, substring, ',');
        string_data.push_back(substring);
    }

    // Loop through string values to create vector of tiles each with their own information
    unsigned int i = 0;
    for (int y = 0; y < m_position.w; y++) {
        for (int x = 0; x < m_position.h; x++) {
            m_tilemap.push_back(new Tile(atoi(string_data[i].c_str()) - 1, x * m_tileWidth, y * m_tileHeight));
            i++;
        }
    }

    m_tileset.reset(new Tileset(tileset, m_tileWidth));
}

Map::~Map() {}

void Map::onUpdate()
{
}

void Map::onRender()
{
    // Render map with currently active camera in mind
    for (int i = 0; i < m_tilemap.size(); i++) {
        m_tileset->renderTile(m_tilemap[i]);
    }
}
}