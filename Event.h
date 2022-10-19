/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Event.h                                                         *
*  @brief    Event class specification                                       *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-19                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#ifndef CGLAB_EVENT_H
#define CGLAB_EVENT_H
#include "import.h"

// TODO complete comments of this class
class Event {
public:
    function<void()> display;
    void (* displayFuncPtr)();
    function<void(unsigned char key, int x, int y)> keyboard;
    void (* keyboardFuncPtr)(unsigned char key, int x, int y);
    function<void(int key, int x, int y)> specialKeyboard;
    void (* specialKeyboardFuncPtr)(int key, int x, int y);
    function<void(int button, int state, int x, int y)> mouse;
    void (*mouseFuncPtr)(int button, int state, int x, int y);
    function<void(int xMouse, int yMouse)> mouseMove;
    void (*mouseMoveFuncPtr)(int xMouse, int yMouse);
    function<void(int w, int h)> reshape;
    void (*reshapeFuncPtr)(int w, int h);

    explicit Event();
};


#endif //CGLAB_EVENT_H
