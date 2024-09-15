#include <log.h>

namespace Eng {
void init()
{
	Log::init();
	Log::GetClientLog()->info("Client init");
}
}