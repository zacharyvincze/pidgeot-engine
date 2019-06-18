#pragma once

#include <vector>
#include <unordered_map>

#include "modules/camera.h"
#include "log.h"

namespace Pidgeot {
    class CameraManager {
        public:
            ~CameraManager();

            inline void pushCamera(Camera* camera) { ENGINE_DEBUG("Pushed Camera: {}", camera->getName()); m_cameras.insert(std::pair<std::string, Camera*>(camera->getName(), camera)); }
            inline void pullCamera(const std::string name) { delete m_cameras.at(name); m_cameras.erase(name); }

            void setActiveCamera(const std::string name);

            inline Camera& getActiveCamera() { return *m_active_camera; }

        private:
            std::unordered_map<std::string, Camera*> m_cameras;
            Camera* m_active_camera;
    };
}