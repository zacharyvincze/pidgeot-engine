#include "utils/uid.h"

namespace Pidgeot {
    size_t UID::m_uid = 1;

    size_t UID::generate() {
        size_t id = m_uid++;
        return id;
    }
}