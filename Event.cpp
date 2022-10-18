#include "Event.h"

/**
 * @
 */
void displayFunc()
{

}

void keyboardFunc(unsigned char key, int x, int y)
{

}

void specialKeyboardFunc(int key, int x, int y)
{

}

void mouseFunc(int button, int state, int x, int y)
{

}

void mouseMoveFunc(int xMouse, int yMouse)
{

}

void reshapeFunc(int w, int h)
{

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
}