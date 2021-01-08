cmake_minimum_required(VERSION 3.12)
project(opengl)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_H ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(COMMON_H ${CMAKE_CURRENT_SOURCE_DIR}/common)
set(RENDERER_H ${CMAKE_CURRENT_SOURCE_DIR}/renderer)
include_directories(${INCLUDE_H} ${COMMON_H} ${RENDERER_H})

link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libs/libglfw3.a)

file(GLOB renderer_files ${CMAKE_CURRENT_SOURCE_DIR}/renderer/*.cpp)
file(GLOB common_files ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp)
file(GLOB glad_files ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/*.c)

add_executable(${PROJECT_NAME} ${glad_files} ${common_files} ${renderer_files} main.cpp)

if(APPLE)
    target_link_libraries(
            ${PROJECT_NAME}
            "-framework Cocoa"
            "-framework OpenGL"
            "-framework GLUT"
            "-framework CoreVideo"
            "-framework IOKit"
    )
endif()