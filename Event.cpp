/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Event.cpp                                                       *
*  @brief    Event class implementation                                      *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-19                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/

#include "Event.h"
#include "Terminal.h"
// TODO complete comments of every function

extern Terminal terminal;
extern deque<deque<string_view>> lineBuffer;
extern int height, width;
extern int mainWindow;
extern map<string_view, unsigned int> commandMap;
void displayFunc()
{
    // set the color of background
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // (optional) add drawing function
    // ...
    //    setPixel(100, 100);
    //    lineDDA(0, 0, 100, 50);
    glFlush();
}


void keyboardFunc(unsigned char key, int x, int y)
{
    // each case means the key pressed
    switch (key) {
        // Enter
        case 13:
        {
            terminal(false);
            lineBuffer.push_back(terminal.split());
            terminal.clear();

            break;
        }
        //Escape
        case 27:
        {
            terminal("Exit successfully!", true);
            glutDestroyWindow(mainWindow);
            exit(0);
            break;
        }
        // Backspace
        case 127:
        {
            terminal.backspace();
            terminal();
            break;
        }
        default:
        {
            terminal.input(key);
            terminal();
            break;
        }
    }
}

void specialKeyboardFunc(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_END:
            break;
        default:
            break;
    }
}

void mouseFunc(int button, int state, int x, int y)
{

}

void mouseMoveFunc(int xMouse, int yMouse)
{
    ;
}

// TODO fix the bug: shape disappearance
void reshapeFunc(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,(GLdouble)w, 0.0,(GLdouble)h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // reset viewport
    glViewport(0,0,w,h);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

    // reset the size of window
    width = w;
    height = h;
}

Event::Event()
{
    display = displayFunc;
    displayFuncPtr = displayFunc;

    keyboard = keyboardFunc;
    keyboardFuncPtr = keyboardFunc;

    specialKeyboard = specialKeyboardFunc;
    specialKeyboardFuncPtr = specialKeyboardFunc;

    mouse = mouseFunc;
    mouseFuncPtr = mouseFunc;

    mouseMove = mouseMoveFunc;
    mouseMoveFuncPtr = mouseMoveFunc;

    reshape = reshapeFunc;
    reshapeFuncPtr = reshapeFunc;
    // initialization of command line
    commandMap["point"]     =   0x00000001;
    commandMap["line"]      =   0x00000002;
    commandMap["linedda"]   =   0x00000003;
    commandMap["linebres"]  =   0x00000004;
    commandMap["circle"]    =   0x00000005;
    commandMap["ellipse"]   =   0x00000006;
    commandMap["poly"]      =   0x00000007;

    commandMap["read"]      =   0xf0000001;
    commandMap["mod"]       =   0xf0000002;
    commandMap["clear"]     =   0xf0000003;
    commandMap["inspect"]   =   0xf0000004;

    commandMap["exit"]      =   0xffffffff;
}