#include "eng.h"

class MyApplication : public Eng::Application {
public:
	bool Close(Eng::WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}

	void OnEvent(Eng::BaseEvent& event)
	{
		Eng::Dispatch<Eng::WindowCloseEvent>(std::bind(&MyApplication::Close, this, std::placeholders::_1),
			event);
	}

	void Run()
	{
		while (m_Running) {
			Render();
		}
	}

private:
	bool m_Running = true;
};

int main()
{
	auto application = MyApplication();
	application.Run();

	return 0;
}
