#pragma once

#include <exception>
#include <cstring>

using std::exception;

class InvalidFormatException: public exception{

    private:
        char *message;

    public:
        InvalidFormatException(const char *);
        const char *what() const throw();
    
};