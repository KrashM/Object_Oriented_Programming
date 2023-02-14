#include <fstream>
#include <iostream>

using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::cout;

int getSize(ofstream& newFile){

    int current = newFile.tellp();
    newFile.seekp(ios::beg, ios::end);
    int size = newFile.tellp();
    newFile.seekp(current, ios::beg);
    return size;
}

int main(){

    ofstream writeFile("myFile.dat", ios::out | ios::binary);

    writeFile.write((const char*)&"Hello world", sizeof("Hello world"));

    int size = getSize(writeFile);
    cout << size << '\n';
    char ch = 'i';
    writeFile.seekp(0, ios::beg);

    // while(!writeFile.eof()){

    //     writeFile.write(&ch, 1);
    //     writeFile.seekp(1, ios::cur);

    // }

    for(int i = 0; i < size; i++){

        cout << writeFile.tellp() << '\n';
        writeFile.write((const char*)&ch, sizeof(ch));
        writeFile.seekp(i, ios::beg);

    }
        
    writeFile.close();


}