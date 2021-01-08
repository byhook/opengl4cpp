cmake_minimum_required(VERSION 3.14)
project(opengl)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libs/libglfw3.a)

file(GLOB chapter_files ${CMAKE_CURRENT_SOURCE_DIR}/chapter/*.cpp)
file(GLOB common_files ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp)
file(GLOB glad_files ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/*.c)

add_executable(opengl ${glad_files} ${common_files} ${chapter_files} main.cpp)

if(APPLE)
    target_link_libraries(opengl "-framework Cocoa")
    target_link_libraries(opengl "-framework OpenGL")
    target_link_libraries(opengl "-framework GLUT")
    target_link_libraries(opengl "-framework CoreVideo")
    target_link_libraries(opengl "-framework IOKit")
endif()