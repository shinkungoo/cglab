#ifndef CGLAB_EVENT_H
#define CGLAB_EVENT_H
#include "import.h"

class Event {
public:
    function<void()> display;
    function<void(unsigned char key, int x, int y)> keyboard;
    function<void(int key, int x, int y)> specialKeyboard;
    function<void(int button, int state, int x, int y)> mouse;
    function<void(int xMouse, int yMouse)> mouseMove;
    function<void(int w, int h)> reshape;
    explicit Event();
};


#endif //CGLAB_EVENT_H
