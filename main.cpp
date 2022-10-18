/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  This strcuture is free software; you can redistribute it and/or modify    *
*  it under the terms of the GNU General Public License version 3 as         *
*  published by the Free Software Foundation.                                *
*                                                                            *
*  You should have received a copy of the GNU General Public License         *
*  along with OST. If not, see <http://www.gnu.org/licenses/>.               *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*  @file     main.cpp                                                        *
*  @brief    This file is the main part of the structure.                    *
*  However, it's not recommended to change anything in this file. You can    *
*  read README or API book and change corresponding part of this structure.  *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-18                                                      *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  What's new in this edition:                                               *
*  1. More flexible.                                                         *
*  All shapes are based on the base class Shape. You can follow the API book *
*  to customize your shape class inherited from the base class. When you     *
*  create new shape in canvas, the object can be named default or you can    *
*  name it use command "name [string of name]"                               *
*  2. Better display of terminal                                             *
*  You can see what you type and modify them in real time now!               *
*  3. command "inspect"                                                      *
*  Because all shapes are object, you can use inspect [name of shape] to     *
*  change your scope to this object. And then, you can use command provided  *
*  by this class.                                                            *
*****************************************************************************/


#include "import.h"
#include "Event.h"
#include "Terminal.h"

extern Terminal terminal;
extern Event event;
extern int height, width;
extern int mainWindow;

int main(int argc, char ** argv)
{
    /*
     * Initialization of window. You can modify the display mode, size of window, position of generation and caption.
     */
    glutInit(&argc, argv);
    // set display mode of window
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
    // set the size of window
    glutInitWindowSize(width, height);
    // set the position of window's generation
    glutInitWindowPosition(500, 500);
    // set the caption of window
    mainWindow = glutCreateWindow("Lab Platform for Computer Graphics");
    /*
     * Initialization of OpenGL. Before you understand the projection, DO NOT MODIFY ANY LINES in this part
     */
    // set 2d-projection, now the left-up corner is (0,0)
    // set the drawing area
    glViewport(0, 0, width, height);
    // set projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,(GLdouble) width , 0.0,(GLdouble) height , -1.0, 1.0);
    // enable the logic-index
    glEnable(GL_COLOR_LOGIC_OP);
    // ... you can enable other functions with glEnable()
    // ...
    /*
     * Initialization of terminal
     * 1. set scope as "canvas"
     * 2. set mode read
     * 3. print init info
     */
    terminal.init_terminal();
    /*
     * Register event. DO NOT MODIFY THIS PART! You should modify the implementation of these function(in Event.cpp)
     */
    // register display function
    glutDisplayFunc(event.displayFuncPtr);
    // register keyboard function
    glutKeyboardFunc(event.keyboardFuncPtr);
    // register special keyboard(like insert, next page and so on) function
    glutSpecialFunc(event.specialKeyboardFuncPtr);
    // register mouse function
    glutMouseFunc(event.mouseFuncPtr);
    // register the motion of mouse function
    glutMotionFunc(event.mouseMoveFuncPtr);
    // register the reshape function to render the window again once the size of window is changed
    glutReshapeFunc(event.reshapeFuncPtr);

    glutMainLoop();

    return 0;
}
