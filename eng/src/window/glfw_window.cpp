#include "glfw_window.h"
#include "events/events.h"

namespace Eng {
static bool s_InitGlfw = false;
WindowInterface* GlfwWindow::Create(WindowProperties properties)
{
	return new GlfwWindow(properties);
}

void GlfwWindow::ErrorCallback(int error, const char* description)
{
	ENG_CORE_ERROR("GFLW error: {}", description);
}

GlfwWindow::GlfwWindow(WindowProperties properties)
{
	ENG_CORE_INFO("Creating window with {}", properties);

	if (!s_InitGlfw) {
		s_InitGlfw = true;
		int success = glfwInit();
		ENG_CORE_ASSERT(success, "Cannot init glfw");
		glfwSetErrorCallback(GlfwWindow::ErrorCallback);
	}

	m_Window = glfwCreateWindow(properties.Width, properties.Height, properties.Title, NULL, NULL);
	ENG_CORE_ASSERT(m_Window, "No window");

	glfwMakeContextCurrent(m_Window);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	ENG_CORE_ASSERT(m_Window, "No glad; I'm sad");
	glfwSetWindowUserPointer(m_Window, &m_Data);

	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
		((GlfwWindow::WindowData*)glfwGetWindowUserPointer(window))->SendEvent(WindowCloseEvent());
	});
	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		auto windowData = (GlfwWindow::WindowData*)glfwGetWindowUserPointer(window);

		switch (action) {
		case GLFW_PRESS:
			windowData->SendEvent(KeyDownEvent(key, false));
		case GLFW_RELEASE:
			windowData->SendEvent(KeyUpEvent(key));
		case GLFW_REPEAT:
			windowData->SendEvent(KeyDownEvent(key, true));
		};
	});
	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
		auto windowData = (GlfwWindow::WindowData*)glfwGetWindowUserPointer(window);
		MouseButton engButton;
		switch (button) {
		case GLFW_MOUSE_BUTTON_1:
			engButton = MouseButtonPrimary;
			break;
		case GLFW_MOUSE_BUTTON_2:
			engButton = MouseButtonSecondary;
			break;
		case GLFW_MOUSE_BUTTON_3:
			engButton = MouseButtonWheel;
			break;
		default:
			ENG_CORE_WARN("Invalid mouse button {}", button);
			return;
		};
		if (action == GLFW_PRESS)
			windowData->SendEvent(MouseDownEvent(engButton));
		else if (action == GLFW_RELEASE)
			windowData->SendEvent(MouseUpEvent(engButton));
	});
	glfwSetDropCallback(m_Window, [](GLFWwindow* window, int path_count, const char* paths[]) {
		for (int i = 0; i < path_count; i++) {
			ENG_CORE_INFO("Drop file {}", paths[i]);
		}
	});
	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
		((GlfwWindow::WindowData*)glfwGetWindowUserPointer(window))->SendEvent(MouseScrollEvent(xoffset, yoffset));
	});
	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
		auto windowData = (GlfwWindow::WindowData*)glfwGetWindowUserPointer(window);
		windowData->SendEvent(MouseMoveEvent(xpos, ypos));
		windowData->MouseX = xpos;
		windowData->MouseY = ypos;
	});
}

void GlfwWindow::SetEventCallback(EventCallback callback)
{
	m_Data.Callback = callback;
}

std::array<int, 2> GlfwWindow::GetSize() const
{
	int width = 0;
	int height = 0;
	glfwGetWindowSize(m_Window, &width, &height);
	return { width, height };
}

GlfwWindow::~GlfwWindow()
{
	ENG_CORE_INFO("Destroying window");
	glfwDestroyWindow(m_Window);
	glfwTerminate();
	s_InitGlfw = false;
}
}