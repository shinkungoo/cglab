/// File name: Terminal.cpp
/// Usage: Completer the implementation of class Terminal.
/// class Terminal is designed for displaying information and settle instructions read from keyboard

#include "Terminal.h"

Terminal::Terminal(const std::string &s)
{
    scope = s;
    state = "(read)";
    line = "";
}

void
Terminal::init_terminal() const
{
    cout << "cglab version: 2.0" << endl;
    cout << "Welcome to use this Lab Platform for Computer Graphics!" << endl;
    cout << "If you want to learn more about this platform, please read README in my github repository:"
         << "https://github.com/shinkungoo/cglab" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "\033[?251";
    cout << scope << state << "<< " << flush;
    for(int i = 0; i < scope.size() + state.size() + strlen("<< "); i ++){
        cout << '\b';
    }
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
Terminal::switch_scope(const std::string &sv) {
    scope = sv;
}

void
Terminal::switch_state(const std::string &sv) {
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
Terminal::operator()(const std::string &s) const
{
    cout << s << endl;
    cout << scope << state << "<< " << line << flush;
    for(int i = 0; i < scope.size() + state.size() + strlen("<< ") + line.size() ; i ++){
        cout << '\b';
    }
}