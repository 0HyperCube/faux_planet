#include "base.h"
namespace Eng {
class KeyDownEvent {
public:
	static BaseEvent GetBaseEvent() { return BaseEvent(EventTypeKeyDown); }
	KeyDownEvent(int key, bool repeat)
		: m_Key(key)
		, m_Repeat(repeat)
	{
	}
	int GetKey() { return m_Key; }
	int IsRepeat() { return m_Repeat; }

private:
	BaseEvent m_Base = GetBaseEvent();
	int m_Key;
	bool m_Repeat;
};
}

template <>
struct fmt::formatter<Eng::KeyDownEvent> : fmt::formatter<std::string> {
	auto format(Eng::KeyDownEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "KeyDownEvent {{ key: {}, repeat: {} }}", (int)my.GetKey(), my.IsRepeat());
	}
};

namespace Eng {
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
}

template <>
struct fmt::formatter<Eng::KeyUpEvent> : fmt::formatter<std::string> {
	auto format(Eng::KeyUpEvent my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "KeyUpEvent {{ key: {} }}", (int)my.GetKey());
	}
};
