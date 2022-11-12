/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Global.h                                                        *
*  @brief    all global variables                                            *
*  This file define a class Global which contains all global variables which *
*  will be used in this structure. You can add new global variables in the   *
*  corresponding part.                                                       *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-11-09                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#ifndef CGLAB_GLOBAL_H
#define CGLAB_GLOBAL_H
#include "Singleton.h"
#include "Shape.h"

class Global: public Singleton<Global> {
    friend class Singleton<Global>;
private:
    Global() = default;
public:
    Global(const Global&) = delete;
    Global& operator=(const Global&) override = delete;
    /*
     * Modify and add your global variables in the following part.
    */
    // size of window
    int width = 1080;
    int height = 720;
    //  id of main window
    int mainWindow = 0;
    // state of modify
    bool isModify = false;
    // state of command or window
    bool isWindow = true;
    // check whether drawing shapes(except point)
    bool isConditional = false;
    // properties of points
    float size = 5.0;
    RGBA color = {0.0, 0.0, 0.0 ,0.0};
    // buffer size
    int pointBufferSize = 100;
    int commandBufferSize = 100;
    // scope
    string scope = "canvas";
    // drawing condition
    string condition = "null";
};

#endif //CGLAB_GLOBAL_H
