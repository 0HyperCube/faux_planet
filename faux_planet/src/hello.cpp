#include "entry_point.h"
#include <stdio.h>

namespace FauxPlanet {
} // namespace FauxPlanet

bool fn(KeyDownEvent& ev)
{
	ENG_INFO("hieeu {}", ev);
	return true;
}

int main()
{
	Eng::init();

	auto event = KeyDownEvent(5);
	KeyDownEvent& one_base = event;
	BaseEvent& base = (BaseEvent&)one_base;
	Eng::Dispatch<KeyDownEvent>(fn, base);

	return 0;
}
