#include "engpch.h"
#include "events/base.h"
#ifndef ENG_WINDOWN_INTERFACE
#define ENG_WINDOWN_INTERFACE

namespace Eng {
class WindowInterface {
public:
	struct WindowProperties {
		int Width;
		int Height;
		const char* Title;
		WindowProperties()
			: Title("Default Window Title")
			, Height(900)
			, Width(900)
		{
		}
		WindowProperties(const char* title, int width, int height)
			: Title(title)
			, Width(width)
			, Height(height)
		{
		}
	};
	static WindowInterface* Create(WindowProperties properties);
	using EventCallback = std::function<void(BaseEvent&)>;
	virtual void SetEventCallback(EventCallback callback) { ENG_CORE_ASSERT(0, "Window should have SetEventCallback implemented"); }
	virtual void Update() { ENG_CORE_ASSERT(0, "Window should have Update implemented"); }
	virtual ~WindowInterface() { }
};
}

template <>
struct fmt::formatter<Eng::WindowInterface::WindowProperties> : fmt::formatter<std::string> {
	auto format(Eng::WindowInterface::WindowProperties my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "WindowInterface::WindowProperties {{ title: \"{}\", width: {}, height: {} }}", my.Title, my.Width, my.Height);
	}
};

#endif