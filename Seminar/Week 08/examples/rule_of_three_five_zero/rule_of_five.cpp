#include <exception>
#include <iostream>
#include <cstddef>
#include <cstring>

class rule_of_five{

public:
    // Parametric constructor
    rule_of_five(char const * const s = ""){

        // If the string is nullptr terminate the constructor
        // and don't allow the object to be created
        if(!s) throw std::invalid_argument("string is nullptr");

        std::size_t n = std::strlen(s) + 1;
        cstring = new char[n];      // allocate
        std::memcpy(cstring, s, n); // populate

    }

    // Destructor
    ~rule_of_five(){

        // We never throw exceptions here!!!
        delete[] cstring; // deallocate
        cstring = nullptr;

    }

    // Copy constructor
    rule_of_five(rule_of_five const &other): rule_of_five(other.cstring){}

    // move constructor
    rule_of_five(rule_of_five &&other) noexcept{
        cstring = std::move(other.cstring);
    }

    // copy assignment
    rule_of_five &operator =(rule_of_five const &other){
        
        if(this == &other) return *this;

        free();
        copy(other);

        return *this = rule_of_five(other);
    }

    // move assignment
    rule_of_five &operator=(rule_of_five &&other) noexcept{

        if(this == &other) return *this;

        free();
        cstring = std::move(other.cstring);
        
        return *this;

    }

private:
    void copy(rule_of_five const &other){

        std::size_t n = std::strlen(other.cstring) + 1;
        cstring = new char[n];
        std::memcpy(cstring, other.cstring, n);

    }

    void free(){

        delete[] cstring;
        cstring = nullptr;

    }

    char *cstring = nullptr; // raw pointer used as a handle to a dynamically-allocated memory block

};