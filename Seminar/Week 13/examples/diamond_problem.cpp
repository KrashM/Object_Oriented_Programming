#include <iostream>
#include <string>

class Entity{

public:
    Entity(unsigned const health): health(health){}

    unsigned get_health() const{
        return health;
    }
    
    virtual void print() const{
        std::cout << "I'm an Entity\n";
    }

private:
    unsigned health;

};

class Player : public virtual Entity{

public:
    Player(std::string const name): name(name), Entity(100){}

    std::string const &get_name() const{
        return name;
    }

    void print() const override{
        std::cout << "I'm a Player\n";
    }

private:
    std::string name;

};

class Bot : public virtual Entity{

public:
    Bot(unsigned const difficulty_level): difficulty_level(difficulty_level), Entity(0){}

    unsigned get_difficulty_level() const{
        return difficulty_level;
    }
    
    void print() const override{
        std::cout << "I'm a Bot\n";
    }

private:
    unsigned difficulty_level;

};

class PlayerAssistant : public Player, public Bot{

public:
    PlayerAssistant(std::string const &name, unsigned const difficulty_level): Player(name), Bot(difficulty_level), Entity(100){}

    // Must be overriden, because it inherits the two print functions from Player and Bot and it becomes ambigues.
    void print() const override{
        std::cout << "I'm a PlayerAssistant\n";
    }

};

int main(){

    PlayerAssistant pa("Jarvis", 10);
    pa.print();

}