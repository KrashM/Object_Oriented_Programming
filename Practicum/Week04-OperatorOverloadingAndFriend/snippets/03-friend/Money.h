#pragma once

#include <iostream>

class Money {
public:
    Money();

    friend std::istream& operator>>(std::istream& in,  Money& money);
    friend std::ostream& operator<<(std::ostream& out, const Money& money);

private:
    unsigned int levs;
    unsigned int stotinkas;
};