set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB_RECURSE GLAD_SOURCES "vendor/glad/*.c")
file(GLOB_RECURSE GLAD_HEADERS "vendor/glad/*.h")
add_library(Glad STATIC ${GLAD_SOURCES} ${GLAD_HEADERS})
target_include_directories(Glad PUBLIC ${CMAKE_SOURCE_DIR}/eng/vendor/glad/include)

file(GLOB IMGUI_SOURCES "vendor/imgui/*.cpp")
file(GLOB IMGUI_HEADERS "vendor/imgui/*.h")
set(IMGUI_SOURCES ${IMGUI_SOURCES} "vendor/imgui/backends/imgui_impl_opengl3.cpp")
set(IMGUI_HEADERS ${IMGUI_SOURCES} "vendor/imgui/backends/imgui_impl_opengl3.h")
add_library(Imgui STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})
target_include_directories(Imgui PUBLIC ${CMAKE_SOURCE_DIR}/eng/vendor/imgui)


set(SPDLOG_BUILD_PIC ON CACHE BOOL "")
set(SPDLOG_COMPILED_LIB ON CACHE BOOL "")
set(SPDLOG_SHARED_LIB ON CACHE BOOL "")
add_subdirectory(vendor/spdlog)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
add_subdirectory(vendor/glfw)

add_compile_definitions(MY_LIB_COMPILING)
file(GLOB_RECURSE ENG_SOURCES "src/*.cpp")
file(GLOB_RECURSE ENG_HEADERS "src/*.h")
add_library(Eng SHARED ${ENG_SOURCES} ${ENG_HEADERS})
target_include_directories(Eng PUBLIC ${CMAKE_SOURCE_DIR}/eng/vendor/glfw/include ${CMAKE_SOURCE_DIR}/eng/vendor/spdlog/include ${CMAKE_SOURCE_DIR}/eng/vendor/glad/include ${CMAKE_SOURCE_DIR}/eng/vendor/imgui src)


target_link_libraries(Eng Glad glfw spdlog::spdlog -std=c++20 Imgui)
target_compile_features(Eng PUBLIC cxx_std_20)
