/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Terminal.h                                                      *
*  @brief    Terminal class specification                                    *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-18                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#ifndef CGLAB_TERMINAL_H
#define CGLAB_TERMINAL_H
#include "import.h"

/**
 * @brief Terminal class
 * This class is designed for displaying information and settle instructions read from keyboard.
 * In this class:
 * TODO: Complete the description of class
 */

class Terminal {
private:
    int stateID;
    string scope;
    string state;
    string line;
public:
    explicit Terminal(const string & s = "canvas");
    void initTerminal() const;
    void input(char c);
    void backspace() noexcept;
    void clear() noexcept;
    void switchScope(const string & sv);
    void switchState(const string & sv);
    void operator()(bool isBackspace = true) const;
    void operator()(const string & s, bool isLast = false) const;
    deque<string_view> split() const;
};


#endif //CGLAB_TERMINAL_H
