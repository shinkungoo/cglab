/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     utilities.cpp                                                   *
*  @brief    Utilities functions definition                                  *
*                                                                            *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-11-12                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/

#include "utilities.h"
#include "Commands.h"


void
initialization(){
    cout << "/*****************************************************************************" << endl;
    cout << "*  Lab Platform for Computer Graphics                                        *" << endl;
    cout << "*  Copyright (C) 2022 Junhao Shen                                            *" << endl;
    cout << "*                                                                            *" << endl;
    cout << "*  version  2.0.0                                                            *" << endl;
    cout << "*  Welcome to use Lab Platform for Computer Graphics!                        *" << endl;
    cout << "*  If you want to learn more about this platform, please visit my github     *" << endl;
    cout << "*  repository: https://github.com/shinkungoo/cglab                           *" << endl;
    cout << "/*****************************************************************************" << endl;
    cout << "============window mode============" << endl;
    cout << "INFO >> Press 's' when cursor in the main window to switch to terminal mode" << endl;

    CommandSet::getInstance().init();
}

deque<string>
split(const string & command)
{
    deque<string> ret;
    string temp;
    istringstream iss(command);
    while (iss >> temp) {
        ret.push_back(temp);
    }

    return std::move(ret);
}

void setPixel(GLint xCoord, GLint yCoord, GLint zCoord, RGBA color, float size)
{
    glPointSize(size);
    glColor4f(color.r, color.g, color.b, color.a);
    glBegin(GL_POINTS);

    glVertex3i(xCoord, yCoord, zCoord);

    glEnd();
    glFlush();
}