#include <iostream>
#include <cstring>
#include <stdexcept>

class Person
{
private:
    char* firstName;
    char* surname;
    int age;

public:
    Person(const char* firstName, const char* surname, int age)
    {
        if (firstName == nullptr || strcmp(firstName, "") == 0)
        {
            throw std::invalid_argument("Invalid first name");
        }

        if (surname == nullptr || strcmp(surname, "") == 0)
        {
            throw std::invalid_argument("Invalid surname");
        }

        if (age < 0 || age > 120)
        {
            throw std::invalid_argument("Invalid age");
        }

        this->firstName = new char[strlen(firstName) + 1];
        strcpy(this->firstName, firstName);

        try
        {
            this->surname = new char[strlen(surname) + 1];
            strcpy(this->surname, surname);
        }
        catch (const std::bad_alloc& ba)
        {
            delete[] this->firstName;
            this->firstName = nullptr;
            
            throw ba;
        }

        this->age = age;
    }
};

int main ()
{
    std::size_t s = 1;
    std::string str;
    str.reserve(s);
    try
    {
        Person p(str.c_str(), str.c_str(), 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}