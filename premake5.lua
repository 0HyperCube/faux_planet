workspace "FauxPlanet"
	configurations { "Debug", "Release" }

	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}"
	objdir "bin-int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}"
	defines { "SPDLOG_COMPILED_LIB" }
	systemversion "latest"
	staticruntime "On"

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

include_things = {
	"eng/src",
	"eng/vendor/spdlog/include",
	"eng/vendor/glfw/include",
}

project "FauxPlanet"
	language "C++"
	kind "ConsoleApp"
	includedirs(include_things)
	files { "faux_planet/src/**.h", "faux_planet/src/**.c", "faux_planet/src/**.cpp" }
	links { "Eng", "spdlog", "glfw", "GL" }

project "spdlog"
	language "C++"
	kind "StaticLib"
	files { "eng/vendor/spdlog/include/**.h", "eng/vendor/spdlog/src/**.cpp" }
	includedirs { "eng/vendor/spdlog/include" }

project "glfw"
	language "C"
	kind "StaticLib"
	function add (src, values)
		for i, value in ipairs(values) do
			files { path.join(src,value) }
		end
	end

	local source = path.join("eng", "vendor", "glfw");
	local src = path.join(source, "src")
	add(src,
		{
			"internal.h", "platform.h", "mappings.h",
			"context.c", "init.c", "input.c", "monitor.c", "platform.c", "vulkan.c", "window.c",
			"egl_context.c", "osmesa_context.c", "null_platform.h", "null_joystick.h",
			"null_init.c", "null_monitor.c", "null_window.c", "null_joystick.c"
		}
	);

	filter "system:macosx"
		add(src, {"cocoa_time.h", "cocoa_time.c", "posix_thread.h", "posix_module.c", "posix_thread.c"})
		defines { "_GLFW_COCOA" }
		add(src, {"cocoa_platform.h", "cocoa_joystick.h", "cocoa_init.m", "cocoa_joystick.m", "cocoa_monitor.m", "cocoa_window.m", "nsgl_context.m"})

	filter "system:windows"
		add(src, {"win32_time.h", "win32_thread.h", "win32_module.c", "win32_time.c", "win32_thread.c"})
		defines { "_GLFW_WIN32" }
		add(src, {"win32_platform.h", "win32_joystick.h", "win32_init.c", "win32_joystick.c", "win32_monitor.c", "win32_window.c", "wgl_context.c"})
	
	filter "system:linux"
		-- General
		add(src, {"posix_time.h", "posix_thread.h", "posix_module.c", "posix_time.c", "posix_thread.c"})
		add(src, {"linux_joystick.h", "linux_joystick.c", "posix_poll.h", "posix_poll.c"})

		-- x11
		defines { "_GLFW_X11"}
		add(src, {"x11_platform.h", "xkb_unicode.h", "x11_init.c", "x11_monitor.c", "x11_window.c", "xkb_unicode.c", "glx_context.c"})

		-- wayland
		defines { "_GLFW_WAYLAND" }
		add(src, {"wl_platform.h", "xkb_unicode.h", "wl_init.c", "wl_monitor.c", "wl_window.c", "xkb_unicode.c"})
		add(path.join(source, "deps", "wayland"), {"wayland.xml", "viewporter.xml", "xdg-shell.xml", "idle-inhibit-unstable-v1.xml", "pointer-constraints-unstable-v1.xml", "relative-pointer-unstable-v1.xml", "fractional-scale-v1.xml", "xdg-activation-v1.xml", "xdg-decoration-unstable-v1.xml"})
		rules { "WaylandHeader" }

rule "WaylandHeader"
	display "wayland-scanner"
	fileextension ".xml"
	buildmessage 'wayland-scanner %{file.relpath}'

	buildcommands { 'wayland-scanner client-header "%{file.relpath}" "eng/vendor/glfw/src/%{file.basename}-client-protocol.h"' }
	buildoutputs { "eng/vendor/glfw/src/%{file.basename}-client-protocol.h" }

	buildcommands { 'wayland-scanner private-code "%{file.relpath}" "eng/vendor/glfw/src/%{file.basename}-client-protocol-code.h"' }
	buildoutputs { "eng/vendor/glfw/src/%{file.basename}-client-protocol-code.h" }

project "Eng"
	language "C++"
	kind "StaticLib"
	files { "eng/src/**.h", "eng/src/**.c", "eng/src/**.cpp" }
	includedirs(include_things)
	pchheader "engpch.h"
	pchsource "eng/src/engpch.cpp"

