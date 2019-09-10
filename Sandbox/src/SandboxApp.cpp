#include <Dolmen.h>

class SandboxApp : public Dolmen::Application
{
public:
	SandboxApp()
	{

	}

	~SandboxApp()
	{

	}
};


Dolmen::Application* Dolmen::CreateApplication()
{
	return new SandboxApp();
}