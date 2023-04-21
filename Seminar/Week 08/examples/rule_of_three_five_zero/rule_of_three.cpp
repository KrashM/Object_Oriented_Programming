#include <iostream>
#include <cstddef>
#include <cstring>

// If a class requires a user-defined destructor, a user-defined copy constructor,
// or a user-defined copy assignment operator, it almost certainly requires all three.

class rule_of_three{

public:
    rule_of_three(char const * const s = ""): rule_of_three(s, std::strlen(s) + 1){}

    ~rule_of_three(){ // I. destructor

        delete[] cstring; // deallocate
        cstring = nullptr;

    }

    rule_of_three(const rule_of_three &other) // II. copy constructor
        : rule_of_three(other.cstring){}

    rule_of_three &operator=(const rule_of_three &other){ // III. copy assignment

        if(this == &other) return *this;

        free();
        copy(other);

        return *this;

    }

    operator char const *() const{ // accessor
        return cstring;
    }

private:
    rule_of_three(char const * const s, std::size_t const n) // to avoid counting twice
        : cstring(new char[n]){     // allocate
        std::memcpy(cstring, s, n); // populate
    }
    
    void copy(rule_of_three const &other){

        std::size_t n{std::strlen(other.cstring) + 1};
        cstring = new char[n];                  // allocate
        std::memcpy(cstring, other.cstring, n); // populate

    }

    void free(){

        delete[] cstring; // deallocate
        cstring = nullptr;

    }

    char *cstring; // raw pointer used as a handle to a dynamically-allocated memory block

};

int main()
{
    rule_of_three o1{"abc"};
    std::cout << o1 << ' ';
    auto o2{o1}; // I. uses copy constructor
    std::cout << o2 << ' ';
    rule_of_three o3("def");
    std::cout << o3 << ' ';
    o3 = o2; // III. uses copy assignment
    std::cout << o3 << ' ';
} // <- II. all destructors are called 'here'