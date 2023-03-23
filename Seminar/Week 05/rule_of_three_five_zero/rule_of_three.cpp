#include <iostream>
#include <cstddef>
#include <cstring>

// If a class requires a user-defined destructor, a user-defined copy constructor,
// or a user-defined copy assignment operator, it almost certainly requires all three.

class rule_of_three
{
    char *cstring; // raw pointer used as a handle to a dynamically-allocated memory block

    rule_of_three(const char *s, std::size_t n) // to avoid counting twice
        : cstring(new char[n])                  // allocate
    {
        std::memcpy(cstring, s, n); // populate
    }

public:
    rule_of_three(const char *s = "")
        : rule_of_three(s, std::strlen(s) + 1) {}

    ~rule_of_three() // I. destructor
    {
        delete[] cstring; // deallocate
    }

    rule_of_three(const rule_of_three &other) // II. copy constructor
        : rule_of_three(other.cstring)
    {
    }

    rule_of_three &operator=(const rule_of_three &other) // III. copy assignment
    {
        if (this == &other)
        {
            return *this;
        }

        std::size_t n{std::strlen(other.cstring) + 1};
        char *new_cstring = new char[n];            // allocate
        std::memcpy(new_cstring, other.cstring, n); // populate
        delete[] cstring;                           // deallocate

        cstring = new_cstring;
        return *this;
    }

    operator const char *() const // accessor
    {
        return cstring;
    }
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