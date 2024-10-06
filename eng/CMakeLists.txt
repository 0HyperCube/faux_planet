set(CMAKE_POSITION_INDEPENDENT_CODE ON)

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
target_include_directories(Eng PUBLIC ${CMAKE_SOURCE_DIR}/eng/vendor/glfw/include ${CMAKE_SOURCE_DIR}/eng/vendor/spdlog/include src)


find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
target_link_libraries(Eng ${OPENGL_LIBRARIES} glfw spdlog::spdlog)
