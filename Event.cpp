#include "Event.h"

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
    keyboard = keyboardFunc;
    specialKeyboard = specialKeyboardFunc;
    mouse = mouseFunc;
    mouseMove = mouseMoveFunc;
    reshape = reshapeFunc;
}