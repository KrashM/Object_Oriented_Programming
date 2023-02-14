#include "Magic.h"
#include <random>

#define EXPAND 2

using std::default_random_engine;
using std::uniform_int_distribution;

void Magic::resize(){

    if(this -> SIZE != this -> CAPACITY) return;

    this -> CAPACITY *= EXPAND;
    int *temp = new int[CAPACITY];
    for(int i = 0; i < this -> SIZE; i++)
        temp[i] = this -> props[i];
    delete[] this -> props;
    this -> props = temp;

}

Magic::Magic(){

    this -> SIZE = 0;
    this -> CAPACITY = 1;
    this -> props = new int[this -> SIZE];

}

Magic::~Magic(){

    delete[] this -> props;

}

void Magic::insert(int prop){

    this -> resize();
    this -> props[this -> SIZE++] = prop;

}

const int Magic::pop(){

    default_random_engine gen;
    uniform_int_distribution<int> distribution(0, this -> SIZE);

    if(this -> SIZE == 0) throw "Hat is empty";
    this -> SIZE--;
    return this -> props[distribution(gen)];
    
}