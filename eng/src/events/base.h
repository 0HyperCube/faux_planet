#ifndef ENG_BASE_EVENT_GUARD
#define ENG_BASE_EVENT_GUARD

namespace Eng {
enum EventType {
	EventTypeMouseDown = 1 << 5,
	EventTypeMouseUp,
	EventTypeMouseMove,
	EventTypeMouseScroll,

	EventTypeKeyDown = 1 << 6,
	EventTypeKeyUp,

	EventTypeWindowClose = 1 << 7,
};

enum EventCategory {
	EventCategoryMouse = 1 << 5,
	EventCategoryKeyboard = 1 << 6,
};

class BaseEvent {
public:
	BaseEvent(EventType eventType)
		: m_EventType(eventType)
	{
	}
	EventType type() { return m_EventType; }

private:
	EventType m_EventType;
};
}
#endif
