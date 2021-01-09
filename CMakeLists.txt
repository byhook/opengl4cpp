cmake_minimum_required(VERSION 3.12)
project(opengl)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_H ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(COMMON_H ${CMAKE_CURRENT_SOURCE_DIR}/common)
set(RENDERER_H ${CMAKE_CURRENT_SOURCE_DIR}/renderer)
include_directories(${INCLUDE_H} ${COMMON_H} ${RENDERER_H})

if(APPLE)
    link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libs/apple/libglfw3.a)
ELSEIF (UNIX)
    link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libs/linux/libglfw3.a)
ENDIF()

file(GLOB renderer_files ${CMAKE_CURRENT_SOURCE_DIR}/renderer/*.cpp)
file(GLOB common_files ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp)
file(GLOB glad_files ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/*.c)

add_executable(${PROJECT_NAME} ${glad_files} ${common_files} main.cpp ${renderer_files})

if(APPLE)
    target_link_libraries(
            ${PROJECT_NAME}
            "-framework Cocoa"
            "-framework OpenGL"
            "-framework GLUT"
            "-framework CoreVideo"
            "-framework IOKit"
    )
ELSEIF (UNIX)
    target_link_libraries(
            ${PROJECT_NAME}
            -lOpenGL
            -lm
            -lXrandr
            -lXi
            -lX11
            -lXxf86vm
            -lpthread
            -ldl
            -lXinerama
            -lXcursor
    )
endif()