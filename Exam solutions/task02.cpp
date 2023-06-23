#include <iostream>
#include <string>
#include <vector>

class Base
{
public:
    virtual int totalTime() const = 0;
    virtual void printPlan() const = 0;
    virtual Base* clone() const = 0;

    virtual ~Base() = default;
};

class SimpleTask : public Base
{
private:
    std::string text;
    int daysToComplete;

public:
    SimpleTask(const std::string& text, int daysToComplete)
        : text(text), daysToComplete(daysToComplete) {}

    virtual int totalTime() const override final
    {
        return this->daysToComplete;
    }

    virtual void printPlan() const override final
    {
        std::cout << text << std::endl;
    }

    virtual SimpleTask* clone() const override final
    {
        return new SimpleTask(*this);
    }

    virtual ~SimpleTask() = default;
};

class CompositeTask : public Base
{
private:
    std::string name;
    std::vector<Base*> subTasks;

    void copy(const CompositeTask& other)
    {
        this->name = other.name;

        for (Base* currentTask : other.subTasks)
        {
            this->subTasks.push_back(currentTask->clone());
        }
    }

    void deallocate()
    {
        for (Base* currentTask : this->subTasks)
        {
            delete currentTask;
        }
    }

public:
    CompositeTask(const std::string& name) : name(name) {}

    CompositeTask(const CompositeTask& other)
    {
        this->copy(other);
    }

    CompositeTask operator = (const CompositeTask& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    virtual ~CompositeTask()
    {
        this->deallocate();
    }

    virtual int totalTime() const override final
    {
        int sum = 0;

        for (Base* currentTask: this->subTasks)
        {
            sum += currentTask->totalTime();
        }

        return sum;
    }

    virtual void printPlan() const override final
    {
        for (Base* currentTask: this->subTasks)
        {
            currentTask->printPlan();
        }
    }

    virtual CompositeTask* clone() const override final
    {
        return new CompositeTask(*this);
    }

    void addNewSubTask(const Base* task)
    {
        this->subTasks.push_back(task->clone());
    }
};

int main ()
{
    CompositeTask code("Write code");
    SimpleTask loginPage("Login page", 3);
    SimpleTask createContactPage("Create Contact page", 2);
    SimpleTask contactListPage("Contact List page", 4);
    code.addNewSubTask(&loginPage);
    code.addNewSubTask(&createContactPage);
    code.addNewSubTask(&contactListPage);

    SimpleTask test("Test app", 2);

    CompositeTask deploy("Deploy");
    SimpleTask awsAccount("Create AWS account", 1);
    SimpleTask runDeployment("Run deployment", 1);
    deploy.addNewSubTask(&awsAccount);
    deploy.addNewSubTask(&runDeployment);

    CompositeTask app("My Contacts");
    app.addNewSubTask(&code);
    app.addNewSubTask(&test);
    app.addNewSubTask(&deploy);

    std::cout << "Total tile: " << app.totalTime() << std::endl;
    app.printPlan();

    return 0;
}