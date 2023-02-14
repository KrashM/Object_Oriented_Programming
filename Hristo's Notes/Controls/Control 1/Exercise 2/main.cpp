#include "Pencil.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;

void insertPencils(Pencil *pencilList, const size_t n){

    ifstream ifs("pencils.txt", ios::in);
    char brand[100];
    unsigned year;
    short hardness;
    for(size_t i = 0; i < n; i++){

        ifs >> brand >> year >> hardness;
        pencilList[i] = Pencil(brand, year, hardness);

    }

}

const size_t getBrandedCount(const char *brand, const Pencil pencilList[], const size_t n){

    size_t branded = 0;

    for(size_t i = 0; i < n; i++)
        if(!strcmp(pencilList[i].getBrand(), brand)) branded++;

    return branded;

}

void getBranded(const char* brand, const Pencil pencilList[], const size_t n, Pencil newList[]){

    size_t index = 0;
    for(size_t i = 0; i < n; i++)
        if(!strcmp(pencilList[i].getBrand(), brand)) newList[index++] = pencilList[i];

}

void writeToFile(const char *brand, const Pencil pencilList[], const size_t n){

    ofstream ofs("branded.dat", ios::out | ios::trunc | ios::binary);
    ofs.write((const char *)&pencilList, sizeof(Pencil) * n);
    ofs.close();

}

int main(){

    size_t n;
    cin >> n;
    Pencil pencilList[n];
    insertPencils(pencilList, n);
    for(int i = 0; i < n; i++)
        cout << pencilList[i];

    char brand[100];
    cin >> brand;

    size_t brandedCount = getBrandedCount(brand, pencilList, n);
    cout << brandedCount << '\n';
    Pencil newList[brandedCount];
    getBranded(brand, pencilList, n, newList);
    writeToFile(brand, newList, brandedCount);

}