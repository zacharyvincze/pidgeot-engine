#include "modules/entity.h"

#include "utils/uid.h"

namespace Pidgeot {
    Entity::Entity(int x, int y, int w, int h)
    : m_position({x,y,w,h}),
    m_id(UID::generate()) {}
}