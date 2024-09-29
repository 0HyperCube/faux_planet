#include "base.h"

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

template <>
struct fmt::formatter<MouseDownEvent> : fmt::formatter<std::string> {
	auto format(MouseDownEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseDownEvent {{ button: {} }}", (int)my.GetButton());
	}
};

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

template <>
struct fmt::formatter<MouseUpEvent> : fmt::formatter<std::string> {
	auto format(MouseUpEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseUpEvent {{ button: {} }}", (int)my.GetButton());
	}
};

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

template <>
struct fmt::formatter<MouseMoveEvent> : fmt::formatter<std::string> {
	auto format(MouseMoveEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseMoveEvent {{ x: {}, y: {} }}", my.GetX(), my.GetY());
	}
};

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

template <>
struct fmt::formatter<MouseScrollEvent> : fmt::formatter<std::string> {
	auto format(MouseScrollEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "MouseScrollEvent {{ x: {}, y: {} }}", my.GetX(), my.GetY());
	}
};
