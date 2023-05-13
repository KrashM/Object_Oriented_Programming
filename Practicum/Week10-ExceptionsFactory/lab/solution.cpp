#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Component
{
private:
    std::string label;

public:
    Component(const std::string& label) 
    {
        if (label == "")
        {   
            throw std::invalid_argument("Invalid label!");
        }

        this->label = label;
    }

    virtual double price() const = 0;

    virtual void output(std::ostream& out) const
    {
        out << this->label << " " << this->price() << std::endl;
    }

    virtual ~Component() = default;
};

class CPU : public Component
{
private:
    unsigned short cores;
    unsigned short clockSpeed;

public:
    CPU(const std::string& label, unsigned short cores, unsigned short clockSpeed)
        : Component(label)
    {
        if (cores < 1 || cores > 8)
        {
            throw std::invalid_argument("Invalid number of cores!");
        }

        this->cores = cores;
        this->clockSpeed = clockSpeed;
    }

    virtual double price() const override final
    {
        return this->cores * 29.99;
    }
};

class Memory : public Component
{
private:
    unsigned short capacity;

public:
    Memory(const std::string& label, unsigned short capacity)
        : Component(label)
    {
        if (capacity < 1 || capacity > 10000)
        {
            throw std::invalid_argument("Invalid capacity!");
        }

        this->capacity = capacity;
    }

    virtual double price() const override final
    {
        return this->capacity * 89.99;
    }
};

class Factory
{
public:
    static Component* create_component()
    {
        std::cout << "What king of component do you want?\n";
        std::cout << "1 - CPU\n";
        std::cout << "2 - Memory\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        Component* result = nullptr;
        std::string label;

        if (choice == 1)
        {

            unsigned short cores, clockSpeed;
            std::cout << "Enter label: ";
            std::cin >> label;
            std::cout << "Enter cores: ";
            std::cin >> cores;
            std::cout << "Enter clock speed: ";
            std::cin >> clockSpeed;

            try
            {
                result = new CPU(label, cores, clockSpeed);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << std::endl;
                result = nullptr;
            }
        }
        else if (choice == 2)
        {
            unsigned short capacity;
            std::cout << "Enter label: ";
            std::cin >> label;
            std::cout << "Enter capacity: ";
            std::cin >> capacity;

            try
            {
                result = new Memory(label, capacity);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << std::endl;
                result = nullptr;
            }
        }

        return result;
    }
};

class Configuration
{
private:
    std::vector<const Component*> components;

    Configuration() = default;

    void insert(const Component* c)
    {
        if (c == nullptr)
        {
            throw std::invalid_argument("Invalid component - nullptr");
        }

        for (std::size_t i = 0; i < components.size(); ++i)
        {
            if (typeid(*c) == typeid(*components[i]))
            {
                throw std::invalid_argument("This type of component already exists!");
            }
        }

        components.push_back(c);
    }

    Configuration(const Configuration& other) = delete;
    Configuration& operator = (const Configuration& other) = delete;

public:

    double price() const
    {
        double result = 0.0;

        for (std::size_t i = 0; i < components.size(); ++i)
        {
            result += components[i]->price();
        }

        return result;
    }

    std::size_t size() const
    {
        return components.size();
    }

    const Component& operator [] (std::size_t index) const
    {
        if (index >= components.size())
        {
            throw std::overflow_error("Invalid index!");
        }

        return *components[index];
    }

    friend std::ostream& operator << (std::ostream& out, const Configuration& configuration)
    {
        for (std::size_t i = 0; i < configuration.components.size(); ++i)
        {
            configuration.components[i]->output(out);
        }

        out << configuration.price() << std::endl;

        return out;
    }

    ~Configuration()
    {
        for (std::size_t i = 0; i < components.size(); ++i)
        {
            delete components[i];
        }
    }

    friend Configuration* create_configuration();
};

Configuration* create_configuration()
    {
        Configuration* result = nullptr;

        try
        {
            result = new Configuration();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            return nullptr;
        }
        
        try
        {
            result->insert(Factory::create_component());
            result->insert(Factory::create_component());
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            delete result;
            return nullptr;
        }
        
        return result;
    }

int main ()
{
    Configuration* configuration = create_configuration();

    if (!configuration)
    {
        std::cout << "Invalid configuration\n";
        return 1;
    }

    std::cout << *configuration;

    return 0;
}