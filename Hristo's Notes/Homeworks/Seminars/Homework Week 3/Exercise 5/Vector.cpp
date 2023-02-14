#include "Vector.h"
#include <iostream>

void Vector::reset(){

    SIZE = 0;
    CAPACITY = 1;
    V = new int[CAPACITY];

}

void Vector::resize(){

    int* r = new int[CAPACITY];
    for(int i = 0; i < SIZE; i++) r[i] = V[i];
    delete[] V;
    // r = V; // Why?!?
    V = r;

}

void Vector::sizeDown(){

    if(SIZE >= CAPACITY / 2) return;
    CAPACITY /= 2;
    resize();

}

void Vector::sizeUp(){

    if(SIZE < CAPACITY) return;
    CAPACITY *= 2;
    resize();

}

Vector::Vector(){ reset(); }
Vector::~Vector(){ delete[] V; }
bool Vector::isEmpty(){ return SIZE == 0; }
int Vector::getCapacity(){ return CAPACITY; }
int Vector::getSize(){ return SIZE; }

int Vector::getAt(int index){
    
    if(!isEmpty() && index < SIZE) return V[index];
    throw -1;
    
}

int Vector::getFirst(){
    
    if(!isEmpty()) return V[0];
    throw -1;

}
int Vector::getLast(){
    
    if(!isEmpty()) return V[SIZE - 1];
    throw -1;
    
}

void Vector::assign(int n, int x){

    delete[] V;
    reset();
    for(int i = 0; i < n; i++) pushBack(x);

}

void Vector::pushBack(int x){

    V[SIZE] = x;
    SIZE++;
    sizeUp();

}

void Vector::popBack(){

    if(isEmpty()) return;
    SIZE--;
    sizeDown();

}

void Vector::removeAt(int i){

    if(isEmpty() || i >= SIZE) return;
    SIZE--;
    for(; i < SIZE; i++) V[i] = V[i + 1];
    sizeDown();

}

void Vector::insert(int i, int x){

    if(i >= SIZE) throw -1;
    SIZE++;
    for(int j = SIZE; j >= i; j--) V[j + 1] = V[j];
    V[i] = x;
    sizeUp();

}

void Vector::erase(int x){

    int offset = 0;

    for(int i = 0; i < SIZE; i++){

        while(V[i + offset] == x) offset++;
        V[i] = V[i + offset];

    }

    SIZE -= offset;

    sizeDown();

}

int greatestPowOfTen(int n){

    int ten = 1;
    while(ten * 10 <= n) ten *= 10;
    return ten;

}

char* Vector::toString(){

    char *result = new char[1024];
    int index = 0;

    for(int i = 0; i < SIZE; i++){

        if(V[i] < 0){

            result[index] = '-';
            index++;
            V[i] *= -1;

        }

        int ten = greatestPowOfTen(V[i]);
        while(ten > 0){

            result[index] = '0' + (V[i] / ten) % 10;
            index++;
            ten /= 10;

        }

        result[index] = ' ';
        index++;

    }

    result[index] = '\0';
    
    return result;

}