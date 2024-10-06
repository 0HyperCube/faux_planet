#include "eng.h"

namespace FauxPlanet {
class Application {
public:
	Application();

private:
	std::unique_ptr<Eng::WindowInterface> m_Window;
};
} // namespace FauxPlanet
