/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Behavior.cpp                                                    *
*  @brief    all mouse behaviors                                             *
*  This file declares all functions which commands will invoke. If you want  *
*  to add your own function, your parameter list of prototypes must be the   *
*  same with the given ones.                                                 *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-11-12                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#include "Behavior.h"
#include "Global.h"
#include "Buffer.h"
#include "Shape.h"

void
Behavior::init() {
    behaviorSet["point"]    =   &b_point;
    behaviorSet["line"]     =   &b_line;
    behaviorSet["circle"]   =   &b_circle;
    behaviorSet["poly"]     =   &b_poly;
}

void
b_point(int x, int y)
{
    auto& global = Global::getInstance();
    auto& buffer = Buffer::getInstance();
    auto p = new Point(x, y, 0);
    p->draw(global.color);
    buffer.shapeBuffer[p->name()] = p;
    cout << "INFO >> Successfully draw a point. ";
    p->info();
}

void
b_line(int x, int y)
{
    ;
}

void
b_circle(int x, int y)
{
    ;
}

void
b_poly(int x, int y)
{
    ;
}