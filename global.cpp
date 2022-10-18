/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     global.cpp                                                      *
*  @brief    all global variables                                            *
*  This file contains all global variables which will be used in this        *
*  structure. You can add new global variables in the corresponding part.    *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-18                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#include "import.h"
#include "Event.h"
#include "Shape.h"
#include "Terminal.h"
/*
 * Use unnamed namespace to store all global variables
 */

// size of window
int width = 1080;
int height = 720;
//  id of main window
int mainWindow = 0;
// state of modify
int isModify = false;
// buffer


// Terminal
Terminal terminal;
// Event
Event event;

enum state {
    is_line,
    is_line_dda,
    is_line_bres,
    is_circle,
    is_ellipse,
    is_poly,
    is_polyfill
};
