workspace "Dolmen"
	architecture "x64"
	startproject "Dolmen"

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
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines {""}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines {""}
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution"
		defines {""}
		runtime "Release"
		optimize "On"