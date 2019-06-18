#include "modules/camera.h"

namespace Pidgeot {
    Camera::Camera(const std::string name, int x, int y, int width, int height)
        : m_position({x,y,width,height}), m_name(name) {

    } 

    Camera::~Camera() {}
}