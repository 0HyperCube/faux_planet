#ifndef GLFW_WINDOW_GUARD
#define GLFW_WINDOW_GUARD

#include "engpch.h"
#include "window_interface.h"

namespace Eng {
class GlfwWindow : public WindowInterface {
public:
	GlfwWindow(WindowProperties properties);
	static WindowInterface* Create(WindowProperties properties);
	void SetEventCallback(EventCallback callback);
	void Update() override
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
	std::array<int, 2> GetSize() const override;
	~GlfwWindow();

private:
	struct WindowData {
		EventCallback Callback;
		double MouseX;
		double MouseY;

		template <typename T>
		void SendEvent(T event)
		{
			ENG_CORE_INFO("Dispatching {}", event);
			ENG_CORE_ASSERT(Callback, "Callback should not be null");
			Callback((BaseEvent&)event);
		}
	};

	GLFWwindow* m_Window;
	WindowData m_Data;
	static void ErrorCallback(int error, const char* description);
};
}

#endif
