#include "InvalidFormatException.hpp"

InvalidFormatException::InvalidFormatException(const char *message){

    this -> message = new char[strlen(message) + 1];
    strcpy(this -> message, message);

}

const char *InvalidFormatException::what() const throw(){ return this -> message; }