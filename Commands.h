/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Commands.h                                                      *
*  @brief    all commands                                                     *
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
#ifndef CGLAB_COMMANDS_H
#define CGLAB_COMMANDS_H
#include "standardLibrary.h"
#include "events.h"
#include "Singleton.h"

class CommandSet : public Singleton<CommandSet> {
    friend class Singleton<CommandSet>;
private:
    CommandSet() = default;
public:
    CommandSet(const CommandSet &) = delete;
    CommandSet& operator=(const CommandSet&) override = delete;

    map<string, void(*)(const deque<string> &)> commandSet;
    void init();
};

/// @param command(from buffer)
/// @brief This function will make user draw points by mouse or draw point
/// in a certain position.
/// @note command format: point [x] [y] [z]
void point(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will make user draw line by mouse or command
/// @note command format: line <-d/-b/-g> [x1] [y1] [z1] [x2] [y2] [z2]
void line(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will make user draw circle by mouse or command
/// @note command format: circle [x0] [y0] [r]
void circle(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will make user draw ellipse by command
/// @note command format: ellipse x0 y0 rx ry
void ellipse(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will make user draw poly by mouse or command
/// @note command format: poly
void poly(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will show the scope you current in.
/// @note command format: scope
void scope(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will clear the canvas
/// @note command format: clear
void clear(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will set value of public global variables
/// @note command format: set <variable name> <value>
void set(const deque<string> & command);

/// @param command(from buffer)
/// @brief This function will reset canvas and buffers
/// @note command format: reset
void reset(const deque<string> & command);

/// @param command(from buffer)
/// @brief It will change the canvas to only-read mod.
/// @note command format: read
void read(const deque<string> & command);

/// @param command(from buffer)
/// @brief It will change the canvas to modify mod.
/// @note command format: mod
void mod(const deque<string> & command);

/// @param command(from buffer)
/// @brief It will list the contents of buffer
/// @note command format: list <-p/-s/-c/-h/-g>
void list(const deque<string> & command);

/// @param command(from buffer)
/// @brief It will inspect a shape on the screen and manipulate it.
/// @note command format: inspect <name of shape object>
void inspect(const deque<string> & command);

/// @param command(from buffer)
/// @brief It will terminate the program.
/// @note command format: exit
void exit(const deque<string> & command);


#endif //CGLAB_COMMANDS_H
