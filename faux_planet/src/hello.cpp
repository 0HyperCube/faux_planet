#include "EntryPoint.h"
#include "test.h"
#include <stdio.h>

namespace FauxPlanet {
} // namespace FauxPlanet

int main()
{
	puts("hello world");
	Eng::print();
	Eng::init();
	return 0;
}