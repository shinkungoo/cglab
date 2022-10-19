/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Terminal.cpp                                                    *
*  @brief    Terminal class implementation                                   *
*  This file implement all member function of Terminal class. Specifically,  *
*  you can read comment above each functions.                                *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-18                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/

// TODO Complete comments of functions
#include "Terminal.h"

extern map<int, string_view> stateMap;

Terminal::Terminal(const string &s)
{
    stateID = 0;
    scope = s;
    state = "(read)";
    line = "";
}

void
Terminal::initTerminal() const
{
    cout << "/*****************************************************************************" << endl;
    cout << "*  Lab Platform for Computer Graphics                                        *" << endl;
    cout << "*  Copyright (C) 2022 Junhao Shen                                            *" << endl;
    cout << "*                                                                            *" << endl;
    cout << "*  version  2.0.0                                                            *" << endl;
    cout << "*  Welcome to use Lab Platform for Computer Graphics!                        *" << endl;
    cout << "*  If you want to learn more about this platform, please visit my github     *" << endl;
    cout << "*  repository: https://github.com/shinkungoo/cglab                           *" << endl;
    cout << "/*****************************************************************************" << endl;
    // hide the cursor
    cout << "\033[?25l";
    cout << scope << state << "<< " << flush;
    for(int i = 0; i < scope.size() + state.size() + strlen("<< "); i ++){
        cout << '\b';
    }
    // initialization of state
    stateMap[0] = "(read)";
    stateMap[1] = "(modify)";
    stateMap[2] = "(modify->line)";
    stateMap[3] = "(modify->lineDDA)";
    stateMap[4] = "(modify->lineBres)";
    stateMap[5] = "(modify->circle)";
    stateMap[6] = "(modify->ellipse)";
    stateMap[7] = "(modify->poly)";
}

void
Terminal::input(char c)
{
    line.push_back(c);
}

void
Terminal::backspace() noexcept
{
    if (!line.empty()) {
       line.pop_back();
    }
}

void
Terminal::clear() noexcept
{
    line.clear();
}

void
Terminal::switchScope(const std::string &sv) {
    scope = sv;
}

void
Terminal::switchState(const std::string &sv) {
    state = sv;
}

void
Terminal::operator()(bool isBackspace) const {
    if(isBackspace){
        cout << scope << state << "<< " << line << flush;
        for(int i = 0; i < scope.size() + state.size() + strlen("<< ") + line.size() ; i ++){
            cout << '\b';
        }
    }else{
        cout << scope << state << "<< " << line << endl;
    }
}

void
Terminal::operator()(const std::string &s, bool isLast) const
{
    cout << s << endl;
    if(!isLast){
        cout << scope << state << "<< " << line << flush;
        for(int i = 0; i < scope.size() + state.size() + strlen("<< ") + line.size() ; i ++){
            cout << '\b';
        }
    }
}

deque<string_view>
Terminal::split() const
{
    deque<string_view> ret;
    string temp;
    istringstream iss(line);
    while (iss >> temp) {
        ret.push_back(temp);
    }

    return std::move(ret);
}