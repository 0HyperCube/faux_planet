workspace "FauxPlanet"
	configurations { "Debug", "Release" }

	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}"
	objdir "bin-int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}"
	defines { "SPDLOG_COMPILED_LIB" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"




project "FauxPlanet"
	language "C++"
	kind "ConsoleApp"
	includedirs { "eng/src", "eng/vendor/spdlog/include" }
	files { "faux_planet/src/**.h", "faux_planet/src/**.c", "faux_planet/src/**.cpp" }
	links { "Eng", "spdlog" }


project "spdlog"
	language "C++"
	kind "StaticLib"
	files { "eng/vendor/spdlog/include/**.h", "eng/vendor/spdlog/src/**.cpp" }
	includedirs { "eng/vendor/spdlog/include" }

project "Eng"
	language "C++"
	kind "StaticLib"
	files { "eng/src/**.h", "eng/src/**.c", "eng/src/**.cpp" }
	includedirs { "eng/src", "eng/vendor/spdlog/include" }
	pchheader "engpch.h"
	pchsource "eng/src/engpch.cpp"

