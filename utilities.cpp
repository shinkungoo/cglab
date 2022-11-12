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
#include "Behavior.h"


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
    Behavior::getInstance().init();
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

double distance(const Point & a, const Point & b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double slope(const Point & a, const Point & b)
{
    if(a.x == b.x){
        return 0;
    }else{
        return static_cast<double>(a.y - b.y) / static_cast<double>(a.x - b.x);
    }
}
