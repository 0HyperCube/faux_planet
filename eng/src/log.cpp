#include "engpch.h"

namespace Eng {
std::shared_ptr<spdlog::logger> Log::s_CoreLog;
std::shared_ptr<spdlog::logger> Log::s_ClientLog;

void Log::init()
{

	spdlog::set_pattern("%^[%T] %n %@: %v%$");
	s_CoreLog = spdlog::stdout_color_mt("Eng");
	s_ClientLog = spdlog::stdout_color_mt("Client");
	s_CoreLog->set_level(spdlog::level::trace);
	s_ClientLog->set_level(spdlog::level::trace);

	ENG_CORE_INFO("Logger init");
}
}
