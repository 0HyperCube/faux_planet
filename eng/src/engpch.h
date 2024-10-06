#ifndef ENG_PCH_GUARD
#define ENG_PCH_GUARD

// Windows
#if defined(_MSC_VER) && MY_LIB_COMPILING
#define ENG_PUBLIC _declspec(dllexport)
#elif defined(_MSC_VER)
#define ENG_PUBLIC __declspec(dllimport)
// Linux
#elif defined(__GNUC__) && MY_LIB_COMPILING
#define ENG_PUBLIC __attribute__((visibility("default")))

// Other
#else
#define ENG_PUBLIC
#endif

#include "GLFW/glfw3.h"

#include "spdlog/spdlog.h"

#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_sinks.h"

#include <iostream>
#include <stdio.h>

#include "log.h"

#endif
