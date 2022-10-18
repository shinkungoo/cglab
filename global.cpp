/// File name: import.h
/// Usage: Contain all all global variables
#include "import.h"
#include "Event.h"
#include "Shape.h"
#include "Terminal.h"
/*
 * Use unnamed namespace to store all global variables
 */

// size of window
int WIDTH = 1080;
int HEIGHT = 720;
//  id of main window
int mainWindow = 0;
// state of modify
int isModify = false;
// buffer


// Terminal
Terminal terminal;
// Event
Event event;
// Command Line Enumeration, if you want to add
enum line {
    point = 1,
    line,
    linedda,
    linebres,
    circle,
    ellipse,
    poly,
    polyfill,
    read,
    mod,
    clear,
    quit,
};

enum state {
    is_line,
    is_line_dda,
    is_line_bres,
    is_circle,
    is_ellipse,
    is_poly,
    is_polyfill
};
