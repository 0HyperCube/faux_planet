#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <stdlib.h>

#define ENG_CORE_INFO(...) (::Eng::Log::GetCoreLog())->log(spdlog::source_loc { __FILE__, __LINE__, __FUNCTION__ }, spdlog::level::info, __VA_ARGS__)
#define ENG_CORE_WARN(...) (::Eng::Log::GetCoreLog())->log(spdlog::source_loc { __FILE__, __LINE__, __FUNCTION__ }, spdlog::level::warn, __VA_ARGS__)
#define ENG_CORE_ERROR(...) (::Eng::Log::GetCoreLog())->log(spdlog::source_loc { __FILE__, __LINE__, __FUNCTION__ }, spdlog::level::err, __VA_ARGS__)

#define ENG_INFO(...) (::Eng::Log::GetClientLog())->log(spdlog::source_loc { __FILE__, __LINE__, __FUNCTION__ }, spdlog::level::info, __VA_ARGS__)
#define ENG_WARN(...) (::Eng::Log::GetClientLog())->log(spdlog::source_loc { __FILE__, __LINE__, __FUNCTION__ }, spdlog::level::warn, __VA_ARGS__)
#define ENG_ERROR(...) (::Eng::Log::GetClientLog())->log(spdlog::source_loc { __FILE__, __LINE__, __FUNCTION__ }, spdlog::level::err, __VA_ARGS__)

#define ENG_CORE_PANIC(...)          \
	{                                \
		ENG_CORE_ERROR(__VA_ARGS__); \
		abort();                     \
	}
#define ENG_CORE_ASSERT(value, ...) \
	if (!value)                     \
	ENG_CORE_PANIC(__VA_ARGS__)
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
