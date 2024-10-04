#include "base.h"
namespace Eng {
enum MouseButton {
	MouseButtonPrimary = 1 << 0,
	MouseButtonSecondary = 1 << 1,
	MouseButtonWheel = 1 << 2,
};

class MouseDownEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeMouseDown); }
	MouseDownEvent(MouseButton button)
		: m_Button(button)
	{
	}
	MouseButton GetButton() { return m_Button; }

private:
	BaseEvent m_Base = GetBaseEvent();
	MouseButton m_Button;
};
}

template <>
struct fmt::formatter<Eng::MouseDownEvent> : fmt::formatter<std::string> {
	auto format(Eng::MouseDownEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseDownEvent {{ button: {} }}", (int)my.GetButton());
	}
};

namespace Eng {
class MouseUpEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeMouseUp); }
	MouseUpEvent(MouseButton button)
		: m_Button(button)
	{
	}
	MouseButton GetButton() { return m_Button; }

private:
	BaseEvent m_Base = GetBaseEvent();
	MouseButton m_Button;
};
}

template <>
struct fmt::formatter<Eng::MouseUpEvent> : fmt::formatter<std::string> {
	auto format(Eng::MouseUpEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseUpEvent {{ button: {} }}", (int)my.GetButton());
	}
};

namespace Eng {
class MouseMoveEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeMouseMove); }
	MouseMoveEvent(double x, double y)
		: m_X(x)
		, m_Y(y)
	{
	}
	double GetX() { return m_X; }
	double GetY() { return m_Y; }

private:
	BaseEvent m_Base = GetBaseEvent();
	double m_X;
	double m_Y;
};
}

template <>
struct fmt::formatter<Eng::MouseMoveEvent> : fmt::formatter<std::string> {
	auto format(Eng::MouseMoveEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseMoveEvent {{ x: {}, y: {} }}", my.GetX(), my.GetY());
	}
};

namespace Eng {
class MouseScrollEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeMouseScroll); }
	MouseScrollEvent(double x, double y)
		: m_X(x)
		, m_Y(y)
	{
	}
	double GetX() { return m_X; }
	double GetY() { return m_Y; }

private:
	BaseEvent m_Base = GetBaseEvent();
	double m_X;
	double m_Y;
};
}
template <>
struct fmt::formatter<Eng::MouseScrollEvent> : fmt::formatter<std::string> {
	auto format(Eng::MouseScrollEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseScrollEvent {{ x: {}, y: {} }}", my.GetX(), my.GetY());
	}
};
