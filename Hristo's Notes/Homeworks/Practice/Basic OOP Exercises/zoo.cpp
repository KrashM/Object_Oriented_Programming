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
        << "\nIt eats meat: " << ((this->eatsMeat) ? "true" : "false")
        << '\n';

}

struct zoo{

    static const int size = 10;
    int lenght = 0;
    animal animals[size];

    void add(animal newAnimal);
    animal fastest();
    animal heaviest();
    animal* notEndangered();
    animal* endangered();
    animal* criticallyEndangered();

};

void zoo::add(animal newAnimal){

    animals[lenght] = newAnimal;
    lenght++;

}

animal zoo::fastest(){

    animal fastest = this->animals[0];
    for(int i = 1; i < this->lenght; i++)
        if(fastest.speed < this->animals[i].speed)
            fastest = this->animals[i];
    
    return fastest;

}

animal zoo::heaviest(){

    animal heaviest = this->animals[0];
    for(int i = 1; i < this->lenght; i++)
        if(heaviest.weight < this->animals[i].weight)
            heaviest = this->animals[i];
    
    return heaviest;

}

animal* zoo::notEndangered(){

    animal *notEndangered = new animal[1];
    int index = 0;
    for(int i = 0; i < this->lenght; i++)
        if(this->animals[i].type == 'n'){

            notEndangered[index] = this->animals[i];
            index++;

        }

    for(int i = 0; i < index; i++)
        notEndangered[i].printInfo();

    return notEndangered;

}

animal* zoo::endangered(){

    animal *endangered = new animal[1];
    int index = 0;
    for(int i = 0; i < this->lenght; i++)
        if(this->animals[i].type == 'e'){

            endangered[index] = this->animals[i];
            index++;

        }

    return endangered;

}

animal* zoo::criticallyEndangered(){

    animal *criticallyEndangered = new animal[1];
    int index = 0;
    for(int i = 0; i < this->lenght; i++)
        if(this->animals[i].type == 'c'){

            criticallyEndangered[index] = this->animals[i];
            index++;

        }

    return criticallyEndangered;

}

int main(){

    int id, weight, speed;
    char type;
    bool eatsMeat;
    zoo myZoo;

    cin >> id >> weight >> speed >> type >> eatsMeat;

    animal myAnimal;
    myAnimal.initAnimal(id, type, weight, speed, eatsMeat);

    myAnimal.printInfo();

    myZoo.add(myAnimal);

    
    cin >> id >> weight >> speed >> type >> eatsMeat;

    myAnimal.initAnimal(id, type, weight, speed, eatsMeat);

    myAnimal.printInfo();

    myZoo.add(myAnimal);

    
    cin >> id >> weight >> speed >> type >> eatsMeat;

    myAnimal.initAnimal(id, type, weight, speed, eatsMeat);

    myAnimal.printInfo();

    myZoo.add(myAnimal);


    cout << "Fastest is:\n";
    myZoo.fastest().printInfo();
    cout << "Heaviest is:\n";
    myZoo.heaviest().printInfo();


    cout << "Not endangered animals are:\n";
    animal *notEndangered = myZoo.notEndangered();
    animal *endPtr = notEndangered + sizeof(*notEndangered)/sizeof(notEndangered[0]);

    while(notEndangered != endPtr){

        notEndangered[0].printInfo();
        notEndangered++;

    }

}

/*
1
12
100
n
1
2
46
200
e
0
3
50
120
c
1
*/