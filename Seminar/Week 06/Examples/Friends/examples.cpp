#include <iostream>
#include <cstring>
#include <fstream>

// friend classes
class A
{
private:
    int a;

public:
    A() { a = 0; }
    friend class B; // Friend Class
};

// forward declaration
class C;

class B
{
private:
    int b;

public:
    B() { b = 1; }
    void showA(A &x)
    {
        // Since B is friend of A, it can access
        // private members of A
        std::cout << "A::a = " << x.a << std::endl;
    }
    void showC(C &x); // Friend function
};

// forward declaration
class C
{
private:
    int c;

public:
    C() { c = 2; }
    friend void B::showC(C &x); // Friend function
    C operator+(const C &other)
    {
        C c;
        c.c = this->c + other.c;
        return c;
    }
    C operator+(int num)
    {
        C c;
        c.c = this->c + num;
        return c;
    }
    friend C operator+(int num, const C &c);
    void setC(int c)
    {
        this->c = c;
    }
};

C operator+(int num, const C &rhs)
{
    C c;
    c.c = rhs.c + num;
    return c;
}

void B::showC(C &x)
{
    // Since showC() is friend of C, it can
    // access private members of C
    std::cout << "C::c = " << x.c << std::endl;
}

class Person
{
private:
    char *name;
    int age;

public:
    Person() : name(nullptr), age(0) {}
    Person(const char *name, int age) : age(age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    // copy constructor and operator= ...
    ~Person()
    {
        delete[] name;
    }
    friend std::istream &operator>>(std::istream &, Person &);
    friend std::ostream &operator<<(std::ostream &, const Person &);
};

std::istream &operator>>(std::istream &is, Person &person)
{
    char input[1024];
    // or "\n" by default if we want full name
    is.getline(input, 1024, ' ');
    delete[] person.name;
    person.name = new char[strlen(input) + 1];
    strcpy(person.name, input);
    is >> person.age;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << person.name << " " << person.age << std::endl;
    return os;
}

int main()
{
    // friend classes
    A a;
    B b;
    C c1;
    C c2;
    c2.setC(10);
    C c3 = c1 + c2;
    C c4 = c1 + 5;
    C c5 = 6 + c1;
    b.showA(a);
    b.showC(c3);
    b.showC(c4);
    b.showC(c5);

    // friend funtions
    std::cout << "Hello persons" << std::endl;
    Person ivan("Ivan", 22);
    std::cout << ivan;
    Person rosi("Rosina", 22);
    std::cout << rosi;
    Person p;
    std::cin >> p;
    std::cout << p;
    std::ofstream os("People.txt");
    os << ivan << rosi << p;
    os.close();
    std::ifstream is("People.txt");
    const int NUMBER_OF_PEOPLE = 3;
    Person people[NUMBER_OF_PEOPLE];
    for (size_t i = 0; i < NUMBER_OF_PEOPLE; i++)
    {
        is >> people[i];
    }
    is.close();
    for (size_t i = 0; i < NUMBER_OF_PEOPLE; i++)
    {
        std::cout << people[i];
    }
}