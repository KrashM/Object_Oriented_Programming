#include <iostream>

using std::cin;
using std::cout;

struct animal
{

    char type;
    int id, weight, speed;
    bool eatsMeat;

    void initAnimal(int id, char type, int weight, int speed, bool eatsMeat);
    void printInfo();

};

void animal::initAnimal(int id, char type, int weight, int speed, bool eatsMeat){

    this->id = id;
    this->type = type;
    this->weight = weight;
    this->speed = speed;
    this->eatsMeat = eatsMeat;

}

void animal::printInfo(){

    cout << "Id is: " << this->id
        << "\nType is: " << ((this->type == 'o') ? "overpopulated" :
                            (this->type == 'n') ? "not endangered" :
                            (this->type == 'e') ? "endangered" :
                            (this->type == 'c') ? "critically endangered" : "None Type!")
        << "\nWeight is: " << this->weight
        << "\nSpeed is: " << this->speed
        << "\nIt eats meat: " << ((this->eatsMeat) ? "true" : "false");

}

int main(){

    int id, weight, speed;
    char type;
    bool eatsMeat;

    cin >> id >> weight >> speed >> type >> eatsMeat;

    animal myAnimal;
    myAnimal.initAnimal(id, type, weight, speed, eatsMeat);

    myAnimal.printInfo();

}
