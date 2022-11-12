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
*  @date     2022-11-09                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#ifndef CGLAB_EVENTS_H
#define CGLAB_EVENTS_H
/*
 * You can only add function which will be registered in the main.cpp.
 */
void displayFunc();
void keyboardFunc(unsigned char key, int x, int y);
void specialKeyboardFunc(int key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMoveFunc(int xMouse, int yMouse);
void reshapeFunc(int w, int h);

#endif //CGLAB_EVENTS_H
