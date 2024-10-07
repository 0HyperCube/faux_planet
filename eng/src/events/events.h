#include "key_event.h"
#include "mouse_event.h"
#include "window_event.h"

namespace Eng {
// class EventDispatcher {
// 	template <typename T>
// 	using EventFn = std::function<bool(T&)>;

// 	template <typename T>
// 	bool Dispatch(EventFn<T> fn)
// 	{
// 		if (T::GetBaseEvent().type() != f)
// 	}

// private:
// 	Event& m_Event;
// };

template <typename T>
bool Dispatch(std::function<bool(T&)> fn, BaseEvent& event)
{
	if (T::GetBaseEvent().type() != event.type())
		return false;
	return fn((T&)event);
}
}