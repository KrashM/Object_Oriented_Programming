#include <iostream>
#include <cstring>
#include <utility>

class rule_of_five
{
    char *cstring; // raw pointer used as a handle to a dynamically-allocated memory block
public:
    rule_of_five(const char *s = "") : cstring(nullptr)
    {
        if (s)
        {
            std::size_t n = std::strlen(s) + 1;
            cstring = new char[n];      // allocate
            std::memcpy(cstring, s, n); // populate
        }
    }

    ~rule_of_five()
    {
        delete[] cstring; // deallocate
    }

    rule_of_five(const rule_of_five &other) // copy constructor
        : rule_of_five(other.cstring)
    {
    }

    rule_of_five(rule_of_five &&other) noexcept // move constructor
        : cstring(std::exchange(other.cstring, nullptr))
    {
    }

    rule_of_five &operator=(const rule_of_five &other) // copy assignment
    {
        return *this = rule_of_five(other);
    }

    rule_of_five &operator=(rule_of_five &&other) noexcept // move assignment
    {
        cstring = std::move(other.cstring);
        return *this;
    }
};