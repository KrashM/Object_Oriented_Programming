#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::ios;

void write(const int arrayOfInts[], const char arrayOfChars[], const double arrayOfDoubles[]){

    // ios::trunc -> Изтрива файла и започва да пише наново
    ofstream out("file.txt", ios::trunc);

    for(int i = 0; i < 5; i++)
        if(i > 0) out << ' ' << arrayOfInts[i];
        else out << arrayOfInts[i];
    out << '\n';
    for(int i = 0; i < 5; i++)
        if(i > 0) out << ' ' << arrayOfChars[i];
        else out << arrayOfChars[i];
    out << '\n';
    for(int i = 0; i < 5; i++)
        if(i > 0) out << ' ' << arrayOfDoubles[i];
        else out << arrayOfDoubles[i];
    out << '\n';

    out.close();

}

void read(int newArrayOfInts[], char newArrayOfChars[], double newArrayOfDoubles[]){

    ifstream in("file.txt");

    for(int i = 0; i < 5; i++)
        in >> newArrayOfInts[i];
    for(int i = 0; i < 5; i++)
        in >> newArrayOfChars[i];
    for(int i = 0; i < 5; i++)
        in >> newArrayOfDoubles[i];

    in.close();

}

int main(){

    int arrayOfInts[] = {1, 2, 3, 4, 5};
    char arrayOfChars[] = "Hello";
    double arrayOfDoubles[] = {1.3, 2.345, 23.45, 1.2, 2.0};

    write(arrayOfInts, arrayOfChars, arrayOfDoubles);

    int newArrayOfInts[5];
    char newArrayOfChars[5];
    double newArrayOfDoubles[5];

    read(newArrayOfInts, newArrayOfChars, newArrayOfDoubles);
    
    for(int i = 0; i < 5; i++)
        cout << newArrayOfInts[i] << ' ' << newArrayOfChars[i] << ' ' << newArrayOfDoubles[i] << '\n';

}