#include "modules/cameramanager.h"

#include <stdexcept>
#include "engine.h"
#include "log.h"

namespace Pidgeot {
    CameraManager::~CameraManager() {
        for (std::unordered_map<std::string, Camera*>::iterator i = m_cameras.begin(); i != m_cameras.end(); i++) {
            delete i->second;
        }
        delete m_active_camera;
    }

    void CameraManager::setActiveCamera(const std::string name) {
        try {
            m_active_camera = m_cameras.at(name);
        } catch (std::out_of_range e) {
            ENGINE_ERROR("CameraManager error when setting active camera: {}", e.what());
            exit(-1);
        }
        ENGINE_DEBUG("Set active camera: {}", m_active_camera->getName());
    }
}