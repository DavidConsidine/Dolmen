#pragma once

#ifdef DM_PLATFORM_WINDOWS

	extern Dolmen::Application* Dolmen::CreateApplication();

	int main(int argc, char** argv)
	{
		auto app = Dolmen::CreateApplication();
		app->Run();
		delete app;
	}

#else
	#error Dolmen does not support this platform.
#endif