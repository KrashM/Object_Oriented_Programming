#include <iostream>

struct Person
{
    const char* name;
    int age;
    double height;
};


void f(const int& a)
{
    std::cout << "The address of a in f() is: " << &a << std::endl;
    // a = 4; --> cannot change the value of const
}

void g(const Person& person)
{
    std::cout << person.name << " " << person.age << std::endl;
    std::cout << "The address of person in g() is: " << &person << std::endl;
}

int main ()
{
    int a = 3;

    f(a);
    f(4); // this also works as the function will not change the value anyway
    // if a literal is passed, a temporary object for it is created

    Person person{"Pesho", 21, 180};

    g(person);
    g({"Vasko", 20, 190}); // will create temporary person

    return 0;
}