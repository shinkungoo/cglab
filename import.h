/// File name: import.h
/// Usage: Contain all necessary header files and using what we will use.
#ifndef CGLAB_IMPORT_H
#define CGLAB_IMPORT_H
/*
 * IO header files
 * <iostream>: print instructions to terminal
 * <filesystem>: (future) read graphics and save graphics files
 * <unistd.h>: support unicode character, by which we can hide the cursor in terminal
 */
#include <iostream>
#include <filesystem>
// only in the unix-like systems have this header file
#if __linux__ or __APPLE__
    #include <unistd.h>
#endif
using std::cout;
using std::endl;
using std::flush;
/*
 * OpenGL
 * <GLUT/glut.h>: An implementation of OpenGL
 * <OpenGL/OpenGL.h>: Basic elements of OpenGL
 */
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>
/*
 * STL container
 * <vector>: contain a sequence of points
 * <deque>: buffer for command lines, points and shapes.
 * <map>:
 * <string_view>: store the scope and state in terminal.
 * <string>: store the command line in terminal.
 */
#include <vector>
#include <deque>
#include <map>
#include <string_view>
#include <string>
using std::vector;
using std::deque;
using std::map;
using std::string_view;
using std::string;
// other STL
#include <algorithm>
#include <functional>
#include <limits>
using std::sort;
using std::function;
using std::bind;

// C header files
#include <cctype>
#include <cstring>
#include <cmath>


#endif //CGLAB_IMPORT_H
