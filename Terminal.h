/// File name: Terminal.h
/// Usage: Declare the specification of class Terminal.
/// class Terminal is designed for displaying information and settle instructions read from keyboard
#ifndef CGLAB_TERMINAL_H
#define CGLAB_TERMINAL_H
#include "import.h"

class Terminal {
private:
    bool isModify;
    string_view scope;
    string_view state;
    string line;
public:
    explicit Terminal(const string & s = "canvas");
    void init_terminal() const;
    void input(char c);
    void backspace() noexcept;
    void clear() noexcept;
    void switch_scope(const string & sv);
    void switch_state(const string & sv);
    void operator()(bool isBackspace = true) const;
    void operator()(const string & s) const;
};


#endif //CGLAB_TERMINAL_H
