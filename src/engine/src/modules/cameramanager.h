#pragma once

#include <vector>
#include <unordered_map>

#include "modules/camera.h"
#include "log.h"

namespace Pidgeot {
    class CameraManager {
        public:
            ~CameraManager();

            inline void pushCamera(Camera* camera) { ENGINE_DEBUG("Pushed Camera: {}", camera->getID()); m_cameras.insert(std::pair<std::string, Camera*>(camera->getID(), camera)); }
            inline void pullCamera(const std::string id) { delete m_cameras.at(id); m_cameras.erase(id); }

            void setActiveCamera(const std::string id);

            inline Camera& getActiveCamera() { return *m_active_camera; }

        private:
            std::unordered_map<std::string, Camera*> m_cameras;
            Camera* m_active_camera;
    };
}