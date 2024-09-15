#include <spdlog/spdlog.h>

namespace Eng {
class Log {
public:
	static void init();

	static std::shared_ptr<spdlog::logger>& GetEngLog() { return s_EngLog; }
	static std::shared_ptr<spdlog::logger>& GetClientLog() { return s_ClientLog; }

private:
	static std::shared_ptr<spdlog::logger> s_EngLog;
	static std::shared_ptr<spdlog::logger> s_ClientLog;
};
}