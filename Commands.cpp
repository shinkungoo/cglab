/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Commands.cpp                                                    *
*  @brief    all buffers                                                     *
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
#include "Commands.h"
#include "Global.h"
#include "Buffer.h"
#include "Shape.h"

void
CommandSet::init() {
    commandSet["point"]     =   &point;
    commandSet["line"]      =   &line;
    commandSet["circle"]    =   &circle;
    commandSet["ellipse"]   =   &ellipse;
    commandSet["poly"]      =   &poly;

    commandSet["clear"]     =   &clear;
    commandSet["set"]       =   &set;
    commandSet["reset"]     =   &reset;

    commandSet["scope"]     =   &scope;
    commandSet["read"]      =   &read;
    commandSet["mod"]       =   &mod;
    commandSet["list"]      =   &list;
    commandSet["inspect"]   =   &inspect;
    commandSet["exit"]      =   &exit;
}

void
point(const deque<string> & command) {
    auto& global = Global::getInstance();
    auto& buffer = Buffer::getInstance();
    if(command.size() == 1){
        cout << "============window mode============" << endl;
        cout << "INFO >> You can draw point by mouse" << endl;
        cout << "INFO >> Press 's' when cursor in the main window to switch to terminal mode" << endl;
        global.isWindow = true;
        global.condition = "point";
    }else if(command.size() == 4){
        if(!global.isConditional){
            auto p = new Point(stoi(command[1]), stoi(command[2]), stoi(command[3]));
            p->draw(global.color);
            buffer.shapeBuffer[p->name()] = p;
            cout << "INFO >> Successfully draw a point. ";
            p->info();
        }else{
            // imitate mouse click
            mouseFunc(GLUT_DOWN, GLUT_LEFT_BUTTON, stoi(command[1]), stoi(command[2]));
        }
    }else{
        cout << "ERROR >> No matching parameter lists. The format of \"point\" is\n"
             << "point [x] [y] [z]" << endl;
    }
}

void
line(const deque<string> & command) {
    ;
}

void
circle(const deque<string> & command) {
    ;
}

void
poly(const deque<string> & command) {
    ;
}

void
ellipse(const deque<string> & command) {
    ;
}

void
scope(const deque<string> & command) {
    cout << "INFO >> Current scope: " << Global::getInstance().scope << endl;
}

void
clear(const deque<string> & command) {
    cout << "INFO >> Clear canvas successfully" << endl;
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void
set(const deque<string> & command) {
    ;
}

void
reset(const deque<string> & command) {
    auto & buffer = Buffer::getInstance();
    cout << "INFO >> Reset canvas and buffer successfully" << endl;
    buffer.commandBuffer.clear();
    buffer.pointBuffer.clear();
    for(auto & s : buffer.shapeBuffer){
        delete s.second;
    }
    buffer.shapeBuffer.clear();
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void
read(const deque<string> & command) {
    Global::getInstance().isModify = false;
    cout << "INFO >> In read mode" << endl;
}

void
mod(const deque<string> & command) {
    Global::getInstance().isModify = false;
    cout << "INFO >> In modify mode" << endl;
}

void
list(const deque<string> & command) {
    auto& global = Global::getInstance();
    auto& buffer = Buffer::getInstance();
    if(command.size() == 2){
        if(command[1] == "-p"){
            cout << "========list of pointBuffer========" << endl;
            cout << "Size of pointBuffer: " << buffer.pointBuffer.size() << endl;
            cout << "Max size of pointBuffer: " << global.pointBufferSize << endl;
            for(const auto & p : buffer.pointBuffer){
                cout << "(" << p.x << ", " << p.y << ", " << p.z << " )" << endl;
            }
            cout << "========end of list========" << endl;
        }else if(command[1] == "-s"){
            cout << "========list of shapeBuffer========" << endl;
            cout << "Size of pointBuffer: " << buffer.shapeBuffer.size() << endl;
            for(const auto & s : buffer.shapeBuffer){
                s.second->info();
            }
            cout << "========end of list========" << endl;
        }else if(command[1] == "-c"){
            cout << "========list of commandBuffer========" << endl;
            cout << "Size of commandBuffer: " << buffer.commandBuffer.size() << endl;
            cout << "Max size of commandBuffer: " << global.commandBufferSize << endl;
            for(const auto & c : buffer.commandBuffer){
                for(auto i = c.begin(); i != c.end(); i ++){
                    cout << *i;
                    if(i != c.end() - 1){
                        cout << ' ';
                    }else{
                        cout << endl;
                    }
                }
            }
            cout << "========end of list========" << endl;
        }else if(command[1] == "-h"){
            cout << "========list of command========" << endl;
            cout<< "point [x] [y] [z]\n"
                << "line <-d/-b/-g> [x1] [y1] [z1] [x2] [y2] [z2]\n"
                << "circle [x0] [y0] [r]\n"
                << "ellipse x0 y0 rx ry\n"
                << "poly\n"
                << "scope\n"
                << "clear\n"
                << "set <variable name> <value>\n"
                << "reset\n"
                << "read\n"
                << "mod\n"
                << "list <-p/-s/-c/-h/-g>\n"
                << "inspect <name of shape object>\n"
                << "exit\n";
            cout << "========end of list========" << endl;
        }else if(command[1] == "-g"){
            cout << "========list of global variables(public)========" << endl;
            cout << "width==" << global.width << endl;
            cout << "height==" << global.height << endl;
            cout << "size==" << global.size << endl;
            cout << "color==(r:"<< global.color.r << ",g:" << global.color.g <<",b:" << global.color.b <<",a:" << global.color.a << ")"<< endl;
            cout << "pointBufferSize=="<< global.pointBufferSize << endl;
            cout << "commandBufferSize==" << global.commandBufferSize << endl;
            cout << "========end of list========" << endl;
        }else{
            cout << "ERROR >> No matching parameter lists. The format of \"list\" is\n"
                 << "list <-p/-s/-c/-h/-g>" << endl;
        }
    }else{
        cout << "ERROR >> No matching parameter lists. The format of \"list\" is\n"
             << "list <-p/-s/-c/-h/-g>" << endl;
    }
}

void
inspect(const deque<string> & command) {
    ;
}

void
exit(const deque<string> & command) {
    if(command.size() == 1){
        cout << "INFO >> Exit successfully!" << endl;
        glutDestroyWindow(Global::getInstance().mainWindow);
        exit(0);
    }else{
        cout << "ERROR >> No matching parameter lists. The format of \"exit\" is\n"
             << "exit" << endl;
    }
}



