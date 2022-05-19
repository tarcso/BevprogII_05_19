cmake_minimum_required(VERSION 3.22)
project(kiderul)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

include_directories(libtarcso)
include_directories(libtarcso/graphicslib)
add_subdirectory(libtarcso)

add_compile_options("-Wall")

file(GLOB sources *.cpp)
add_executable(main ${sources})
target_link_libraries(main libtarcso)
