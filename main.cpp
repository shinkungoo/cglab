/**
 * This Lab Platform for Computer Graphics is designed by Junhao Shen. All Rights Reserved.
 * Platform Edition: 2.0
 * Release Time:
 * What's new:
 * 1. OOC
 * 2. API
 * 3. Better Terminal Diwplay.
 **/
/// File name: main.cpp
/// Usage:

#include "import.h"
#include "Event.h"
#include "Terminal.h"

extern Terminal terminal;
extern Event event;

int main(int argc, char ** argv)
{
    /*
     * Initialization of window. You can modify the display mode, size of window, position of generating and caption.
     */

    /*
     * Initialization of OpenGL. Before you understand the projection, DO NOT MODIFY ANY LINES in this part
     */

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

    return 0;
}
