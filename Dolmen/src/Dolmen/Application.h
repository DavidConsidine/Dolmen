#pragma once

#include "Core.h"

namespace Dolmen
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		inline static Application& Get() { return *s_AppInst; }

	private:
		static Application* s_AppInst;
	};

	Application* CreateApplication();
}