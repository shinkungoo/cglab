/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Behavior.h                                                      *
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
#ifndef CGLAB_BEHAVIOR_H
#define CGLAB_BEHAVIOR_H
#include "standardLibrary.h"
#include "events.h"
#include "Singleton.h"

class Behavior: public Singleton<Behavior>{
    friend class Singleton<Behavior>;
private:
    Behavior() = default;
public:
    Behavior(const Behavior &) = delete;
    Behavior& operator=(const Behavior&) override = delete;

    map<string, void(*)(int, int)> behaviorSet;
    void init();
};

void b_point(int x, int y);

void b_line(int x, int y);

void b_circle(int x, int y);

void b_poly(int x, int y);

#endif //CGLAB_BEHAVIOR_H
