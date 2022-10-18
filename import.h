/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     import.h                                                        *
*  @brief    header files inclusion                                          *
*  This file contains all STANDARD header files which will be used in this   *
*  structure. So if you want to add header files, DO NOT include customized  *
*  header files.                                                             *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-18                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
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
 * <map>: manage all command lines
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
/*
 * STL utility
 * <algorithm>: to complete some algorithms used in drawing
 * <functional>: encapsulate some functions
 * <limits>: provide max and min of number
 */
#include <algorithm>
#include <functional>
#include <limits>
using std::sort;
using std::function;
using std::bind;
/*
 * C Standard Library
 * <cctype>: decide the types
 * <cstring>: using some functions to manipulate C string
 * <cmath>: use math functions
 */
#include <cctype>
#include <cstring>
#include <cmath>

#endif //CGLAB_IMPORT_H
