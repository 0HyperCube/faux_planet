#include "application.h"

namespace FauxPlanet {
bool fn(Eng::KeyDownEvent& ev)
{
	ENG_INFO("hieeu {}", ev);
	return true;
}

Application::Application()
{
	Eng::init();

	m_Window = std::unique_ptr<Eng::WindowInterface>(Eng::GlfwWindow::Create(Eng::WindowInterface::WindowProperties()));
	while (true) {
		glClearColor(1., 1., 0., 1.);

		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->Update();
	}

	auto event = Eng::KeyDownEvent(5);
	Eng::KeyDownEvent& one_base = event;
	Eng::BaseEvent& base = (Eng::BaseEvent&)one_base;
	Eng::Dispatch<Eng::KeyDownEvent>(fn, base);
}
} // namespace FauxPlanet
