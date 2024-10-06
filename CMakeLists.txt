cmake_minimum_required(VERSION 3.22)
project(FauxPlanet)

# Put libraries and runtime outputs in the same directory (so they can find each other ❤️)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(eng)
add_subdirectory(faux_planet)
