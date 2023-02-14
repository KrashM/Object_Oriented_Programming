#include "MessageException.hpp"
#include <cstring>

MessageException::MessageException(const char *message){

    this -> message = new char[strlen(message) + 1];
    strcpy(this -> message, message);  

}

const char *MessageException::what() const throw(){ return this -> message; }