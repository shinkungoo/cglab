cmake_minimum_required(VERSION 3.22)
project(cglab)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(cglab main.cpp global.cpp import.h Terminal.cpp Terminal.h Shape.cpp Shape.h Event.cpp Event.h)
target_link_libraries(cglab ${GLUT_LIBRARY} ${OPENGL_LIBRARY})