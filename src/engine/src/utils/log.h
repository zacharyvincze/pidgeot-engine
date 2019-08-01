#pragma once

#include "spdlog/spdlog.h"

namespace Pidgeot {
class Log {
public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& getEngineLogger() { return s_core_logger; }
    inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_client_logger; }

private:
    static std::shared_ptr<spdlog::logger> s_core_logger;
    static std::shared_ptr<spdlog::logger> s_client_logger;
};
}

#define ENGINE_TRACE(...) ::Pidgeot::Log::getEngineLogger()->trace(__VA_ARGS__)
#define ENGINE_DEBUG(...) ::Pidgeot::Log::getEngineLogger()->debug(__VA_ARGS__)
#define ENGINE_INFO(...) ::Pidgeot::Log::getEngineLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...) ::Pidgeot::Log::getEngineLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...) ::Pidgeot::Log::getEngineLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL(...) ::Pidgeot::Log::getEngineLogger()->fatal(__VA_ARGS__)

#define APP_TRACE(...) ::Pidgeot::Log::getClientLogger()->trace(__VA_ARGS__)
#define APP_DEBUG(...) ::Pidgeot::Log::getClientLogger()->debug(__VA_ARGS__)
#define APP_INFO(...) ::Pidgeot::Log::getClientLogger()->info(__VA_ARGS__)
#define APP_WARN(...) ::Pidgeot::Log::getClientLogger()->warn(__VA_ARGS__)
#define APP_ERROR(...) ::Pidgeot::Log::getClientLogger()->error(__VA_ARGS__)
#define APP_FATAL(...) ::Pidgeot::Log::getClientLogger()->fatal(__VA_ARGS__)
