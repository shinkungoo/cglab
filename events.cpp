/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Event.cpp                                                       *
*  @brief    Event class implementation                                      *
*  Despite the implementation of events, here are also some vital functions  *
*  in this structure. Before modify this part, please read comments CAREFULLY*
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-19                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/

#include "events.h"
#include "utilities.h"
#include "Buffer.h"
#include "Commands.h"
#include "Shape.h"
#include "Global.h"

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
    auto & global = Global::getInstance();
    auto & buffer = Buffer::getInstance();
    auto & commandSet = CommandSet::getInstance().commandSet;
    if(key == 's'){
        string tempCommand;
        cout << "============terminal mode============" << endl;
        cout << "INFO >> Input EOF or some state-switch commands to switch to window mode" << endl;
        global.isWindow = false;
        cin.clear();
        clearerr(stdin);
        fflush(stdin);
        while(getline(cin, tempCommand) && !global.isWindow){
            auto tempSplitCommand = split(tempCommand);
            buffer.commandBuffer.push_back(tempSplitCommand);
            if(commandSet[buffer.commandBuffer.back()[0]]){
                commandSet[buffer.commandBuffer.back()[0]](tempSplitCommand);
                if(buffer.commandBuffer.size() > global.commandBufferSize){
                    buffer.commandBuffer.pop_front();
                }
            }else{
                cout << "ERROR >> command \"" << tempCommand << "\" undefined in this framework." <<endl;
                // Remove undefined command from buffer
                buffer.commandBuffer.pop_back();
            }
        }
        cout << "============window mode============" << endl;
        cout << "INFO >> Press 's' when cursor in the main window to switch to terminal mode" << endl;
        global.isWindow = true;
    }
}

void specialKeyboardFunc(int key, int x, int y)
{
    ;
}

void mouseFunc(int button, int state, int x, int y)
{
    auto& global = Global::getInstance();
    auto& buffer = Buffer::getInstance();
    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON){
            if(global.condition == "point"){
                ;
            }
        }else if(button == GLUT_RIGHT_BUTTON){
            cout << "INFO >> Current Pos:(" << x << ", " << y << ")" << endl;
        }
    }
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
    Global::getInstance().width = w;
    Global::getInstance().height = h;
}


