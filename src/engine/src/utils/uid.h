#pragma once

#include <stdio.h>

namespace Pidgeot {
    class UID {
        private:
            static size_t m_uid;
        public:
            static size_t generate();
    };
}