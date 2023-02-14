#pragma once

#include <exception>

using std::exception;

class MessageException: public exception{

    public:
        MessageException(const char *);
        const char *what() const throw();

    private:
        char *message;

};