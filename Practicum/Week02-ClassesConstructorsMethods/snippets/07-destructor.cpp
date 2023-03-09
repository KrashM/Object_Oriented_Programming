#include <iostream>
#include <cstring>
#include <cassert>

class Teacher
{
private:
    char* name;
    char* subject;
    
public:
    Teacher(const char* name, const char* subject)
        : name(nullptr), subject(nullptr)
    {
        std::cout << "Inside constuctor" << std::endl;

        setName(name);

        if (!this->name) {            
            return;
        }

        setSubject(subject);

        if (!this->subject) {
            delete[] this->name;

            return;
        }
    }

    void setName(const char* name) {
        delete[] this->name;
        this->name = new (std::nothrow) char[strlen(name) + 1];

        if (!this->name)
        {
            std::cout << "Memory problem" << std::endl;
            return;
        }
        
        strcpy(this->name, name);
    }

    void setSubject(const char* subject) {
        delete[] this->subject;
        this->subject = new (std::nothrow) char[strlen(subject) + 1];
        
        if (!this->subject)
        {
            std::cout << "Memory problem" << std::endl; 
            return;
        }
        
        strcpy(this->subject, subject);
    }

    void print() const
    {
        std::cout << "My name is " << this->name << " and I am teaching " << this->subject << "." << std::endl;
    }

    ~Teacher()
    {
        std::cout << "Inside destuctor" << std::endl;

        delete[] this->name;
        delete[] this->subject;
    }
};

int main ()
{
    // Teacher teacher("Borislav Draganov", "DIS2");

    // teacher.print();

    Teacher* dynamicallyAllocatedTeacher = new (std::nothrow) Teacher("Bogdan Alexandrov", "Geometry");
    if (!dynamicallyAllocatedTeacher)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    dynamicallyAllocatedTeacher->print();

    delete dynamicallyAllocatedTeacher;
    return 0;
}
