#include <iostream>
#include <cstring>

struct Person
{
    char* name;
    int age;
};

// the function returns true if the initialization is successfull
bool init(Person& person, const char* name, int age)
{
    person.name = new (std::nothrow) char[strlen(name) + 1];
    if (!person.name)
    {
        return false;
    }

    strcpy(person.name, name);
    person.age = age;
    
    return true;
}

void print(const Person& person)
{
    std::cout << person.name << " " << person.age << std::endl;
}

int main ()
{
    Person lyubo;

    bool initialization = init(lyubo, "Luben Georgiev", 21);
    if (!initialization)
    {
        std::cout << "Memory problem" << std::endl;
        return 1;
    }

    print(lyubo);
    delete[] lyubo.name;

    return 0;
}