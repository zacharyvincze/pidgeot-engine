#include "modules/camera.h"

namespace Pidgeot {
Camera::Camera(const std::string id, int x, int y, int width, int height)
    : position({ x, y, width, height })
    , m_id(id)
{
}

Camera::~Camera() {}
}