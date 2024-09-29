#include "base.h"

class KeyDownEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeKeyDown); }
	KeyDownEvent(int key)
		: m_Key(key)
	{
	}
	int GetKey() { return m_Key; }

private:
	BaseEvent m_Base = GetBaseEvent();
	int m_Key;
};

template <>
struct fmt::formatter<KeyDownEvent> : fmt::formatter<std::string> {
	auto format(KeyDownEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "KeyDownEvent {{ key: {} }}", (int)my.GetKey());
	}
};

class KeyUpEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeKeyUp); }
	KeyUpEvent(int key)
		: m_Key(key)
	{
	}
	int GetKey() { return m_Key; }

private:
	BaseEvent m_Base = GetBaseEvent();
	int m_Key;
};

template <>
struct fmt::formatter<KeyUpEvent> : fmt::formatter<std::string> {
	auto format(KeyUpEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "KeyUpEvent {{ key: {} }}", (int)my.GetKey());
	}
};
