workspace "Calculator"
	architecture "x64"
	startproject "Calculator"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}.%{cfg.system}.%{cfg.architecture}"

project "Calculator"
	location "Calculator"
	kind "ConsoleApp" -- dynamic lib
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h", -- ** search child folders
		"%{prj.name}/src/**.cpp", -- include cpp files
		"%{prj.name}/vendor/glad.c", -- for glad.c 

		"%{prj.name}/vendor/ImGui/imgui*.cpp",
		"%{prj.name}/vendor/ImGui/imgui*.h", 

		"%{prj.name}/vendor/ImGui/backends/imgui_glfw.*",
		"%{prj.name}/vendor/ImGui/imgui_opengl3*"

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/include"
	}

	libdirs
	{
		"%{prj.name}/vendor/lib"
	}

	links
	{
		"glfw3",
        "opengl32"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"


