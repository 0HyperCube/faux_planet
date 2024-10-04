#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <stdlib.h>

#define ENG_CORE_TRACE(...) SPDLOG_LOGGER_TRACE(::Eng::Log::GetCoreLog(), __VA_ARGS__)
#define ENG_CORE_DEBUG(...) SPDLOG_LOGGER_DEBUG(::Eng::Log::GetCoreLog(), __VA_ARGS__)
#define ENG_CORE_INFO(...) SPDLOG_LOGGER_INFO(::Eng::Log::GetCoreLog(), __VA_ARGS__)
#define ENG_CORE_WARN(...) SPDLOG_LOGGER_WARN(::Eng::Log::GetCoreLog(), __VA_ARGS__)
#define ENG_CORE_ERROR(...) SPDLOG_LOGGER_ERROR(::Eng::Log::GetCoreLog(), __VA_ARGS__)
#define ENG_CORE_PANIC(...)          \
	{                                \
		ENG_CORE_ERROR(__VA_ARGS__); \
		abort();                     \
	}
#define ENG_CORE_ASSERT(value, ...) \
	if (!value)                     \
	ENG_CORE_PANIC(__VA_ARGS__)

#define ENG_TRACE(...) SPDLOG_LOGGER_TRACE(::Eng::Log::GetClientLog(), __VA_ARGS__)
#define ENG_DEBUG(...) SPDLOG_LOGGER_DEBUG(::Eng::Log::GetClientLog(), __VA_ARGS__)
#define ENG_INFO(...) SPDLOG_LOGGER_INFO(::Eng::Log::GetClientLog(), __VA_ARGS__)
#define ENG_WARN(...) SPDLOG_LOGGER_WARN(::Eng::Log::GetClientLog(), __VA_ARGS__)
#define ENG_ERROR(...) SPDLOG_LOGGER_ERROR(::Eng::Log::GetClientLog(), __VA_ARGS__)
#define ENG_PANIC(...)          \
	{                           \
		ENG_ERROR(__VA_ARGS__); \
		abort();                \
	}
#define ENG_ASSERT(value, ...) \
	if (!value)                \
	ENG_PANIC(__VA_ARGS__)

namespace Eng {

class Log {
public:
	static std::shared_ptr<spdlog::logger>& GetCoreLog() { return s_CoreLog; }
	static std::shared_ptr<spdlog::logger>& GetClientLog() { return s_ClientLog; }

	static void init();

private:
	static std::shared_ptr<spdlog::logger> s_CoreLog;
	static std::shared_ptr<spdlog::logger> s_ClientLog;
};
}
