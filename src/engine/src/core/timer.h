#pragma once

#include <chrono>

namespace Pidgeot {
class Timer {
public:
    inline long ticks() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - m_start).count(); }
    inline void reset() { m_start = std::chrono::steady_clock::now(); }

private:
    std::chrono::steady_clock::time_point m_start;
};
}