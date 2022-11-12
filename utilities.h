/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     utilities.h                                                     *
*  @brief    Utilities functions declaration                                 *
*                                                                            *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-11-12                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#ifndef CGLAB_UTILITIES_H
#define CGLAB_UTILITIES_H
#include "standardLibrary.h"
#include "Shape.h"
#include "Global.h"

void initialization();
deque<string> split(const string & command);
void setPixel(GLint xCoord, GLint yCoord, GLint zCoord,
              RGBA color = Global::getInstance().color,
              float size = Global::getInstance().size);

#endif //CGLAB_UTILITIES_H
