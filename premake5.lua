workspace "Dolmen"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Dolmen"
	location "Dolmen"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dpch.h"
	pchsource "Dolmen/src/dpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"DM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution"
		defines "DM_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Dolmen/src"
	}

	links
	{
		"Dolmen"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"DM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Distribution"
		defines "DM_DIST"
		runtime "Release"
		optimize "on"