#include "log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Eng {
std::shared_ptr<spdlog::logger> Log::s_EngLog;
std::shared_ptr<spdlog::logger> Log::s_ClientLog;

void Log::init()
{
	spdlog::set_pattern("%^[%T] %n %@: %v%$");
	s_EngLog = spdlog::stdout_color_mt("Eng");
	s_ClientLog = spdlog::stdout_color_mt("Client");
	s_EngLog->set_level(spdlog::level::trace);
	s_ClientLog->set_level(spdlog::level::trace);

	SPDLOG_LOGGER_INFO(s_ClientLog, "hi");
	SPDLOG_LOGGER_INFO(s_ClientLog, "hei");
	s_ClientLog->info("we");
}
}