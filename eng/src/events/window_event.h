#include "base.h"
namespace Eng {

class WindowCloseEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeWindowClose); }
	WindowCloseEvent()
	{
	}

private:
	BaseEvent m_Base = GetBaseEvent();
};
}

template <>
struct fmt::formatter<Eng::WindowCloseEvent> : fmt::formatter<std::string> {
	auto format(Eng::WindowCloseEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "WindowCloseEvent");
	}
};
