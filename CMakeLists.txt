cmake_minimum_required(VERSION 3.14)
project(opengl)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libs/libglfw3.a)

add_executable(opengl main_glsl.cpp glad.c)

if(APPLE)
    target_link_libraries(opengl "-framework Cocoa")
    target_link_libraries(opengl "-framework OpenGL")
    target_link_libraries(opengl "-framework GLUT")
    target_link_libraries(opengl "-framework CoreVideo")
    target_link_libraries(opengl "-framework IOKit")
endif()

