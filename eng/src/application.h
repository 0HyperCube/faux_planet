
#include "engpch.h"
#include "events/events.h"
#include "layers/layer_stack.h"
#include "window/glfw_window.h"

namespace Eng {
class Application {
public:
	Application();
	void Render();

private:
	virtual void OnEvent(BaseEvent& event) { }
	std::unique_ptr<Eng::WindowInterface> m_Window;
};
} // namespace Eng