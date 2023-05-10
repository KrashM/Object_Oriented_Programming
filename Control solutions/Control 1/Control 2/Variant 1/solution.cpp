#include <string>
#include <vector>
#include <iostream>

class Printable
{
public:
    virtual void PrintInfo() const = 0;
    
    virtual Printable* clone() const = 0;
    
    virtual ~Printable() = default;
};

class Member: public Printable
{
private:
    std::string name;

public:
    Member(const std::string& name) : name(name) {}

    virtual void PrintInfo() const override final
    {
        std::cout << this->name << std::endl;
    }
    
    virtual Member* clone() const override final
    {
        return new Member(*this);
    }

    virtual ~Member() = default;
};

class Department: public Printable
{
private:
    std::vector<Printable*> subDepartments;

    void copy(const Department& other)
    {
        for (std::size_t i = 0; i < other.subDepartments.size(); ++i)
        {
            this->subDepartments.push_back(other.subDepartments[i]->clone());
        }
    }

    void deallocate()
    {
        for (std::size_t i = 0; i < this->subDepartments.size(); ++i)
        {
            delete this->subDepartments[i];
        }
    }

public:
    Department() = default;

    Department(const Department& other)
    {
        this->copy(other);
    }

    Department& operator = (const Department& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    void add(const Printable* toAdd)
    {
        this->subDepartments.push_back(toAdd->clone());
    }

    virtual void PrintInfo() const override final
    {
        for (std::size_t i = 0; i < this->subDepartments.size(); ++i)
        {
            this->subDepartments[i]->PrintInfo();
        }
    }
    
    virtual Department* clone() const override final
    {
        return new Department(*this);
    }

    virtual ~Department()
    {
        this->deallocate();
    }
};

int main ()
{
    Member petar("Petar Petrov");
    Member maria("Maria Ivanova");
    Member ivanka("Ivanka Marinova");
    Member ivan("Ivan Ivanov");

    Department design;
    design.add(&petar);

    Department engineering;
    engineering.add(&maria);
    engineering.add(&ivanka);

    Department productDevelopment;
    productDevelopment.add(&ivan);
    productDevelopment.add(&design);
    productDevelopment.add(&engineering);

    productDevelopment.PrintInfo();

    return 0;
}