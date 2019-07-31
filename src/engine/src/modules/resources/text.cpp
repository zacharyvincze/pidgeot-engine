#include "text.h"

#include "engine.h"

namespace Pidgeot {
Text::Text(const std::string filepath, int char_width, int char_height)
    : m_char_width(char_width)
    , m_char_height(char_height)
{
    m_font_texture = Engine::get().getResourceManager().get<Pidgeot::Texture>(filepath);
    m_char_map.resize(0xFF);

    for (int i = 33; i != 126; i++) {
        m_char_map[i] = { (i - 32) * m_char_width, 0, m_char_width, m_char_height };
    }
}

Text::~Text()
{
    delete m_font_texture;
}

void Text::print(const std::string text, int x, int y)
{
    SDL_Rect dest_rect = { x, y, m_char_width, m_char_height };
    for (int i = 0; i < text.size(); i++) {
        Engine::get().getRenderer().drawTexture(m_font_texture, &m_char_map[text[i]], &dest_rect);
        dest_rect.x += m_char_width;
    }
}
}