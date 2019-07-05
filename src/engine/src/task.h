#pragma once

namespace Pidgeot {
    class Task {
        public:
            virtual void onUpdate() {}
            virtual void onRender() {}
    };   
}