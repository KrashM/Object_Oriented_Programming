#include <iostream>
#include <cstring>
#include <cassert>

const std::size_t MAX_NAME_SIZE = 50;

struct Person
{
private:
    char name[MAX_NAME_SIZE];
    int age;
    double weight;

public:
    Person(const char* name, int age, double weight)
    {
        strcpy(this->name, name);
        this->age = age;
        this->weight = weight;
    }

    Person()
    {
        strcpy(this->name, "");
        this->age = 0;
        this->weight = 0.0;
    }

    void print()
    {
        std::cout << "My name is " << this->name << ". I am " << this->age << 
                    " years old and I am " << this->weight << " kg." << std::endl;
    }

    // Person() : Person("", 0, 0.0) {}
};

int main ()
{
    Person person("Stefcho", 20, 77.7);

    person.print();

    // std::cout << person.age << std::endl;
    
    return 0;
}