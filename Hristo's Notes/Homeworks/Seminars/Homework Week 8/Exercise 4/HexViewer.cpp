#include "HexViewer.hpp"
#include <fstream>
#include <cstring>
#include <iostream>

#define FILE_CANNOT_OPEN -1
#define FILE_COULD_NOT_CLOSE -2

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;

size_t getFileSize(ifstream &in){

    size_t currentPos = in.tellg();
	in.seekg(ios::beg, ios::end);
	size_t size = in.tellg();

	in.seekg(currentPos);
	return size;

}

void resize(char *&content, const size_t newSize){

    size_t length = strlen(content);
    char *temp = new char[newSize + 1];
    for(int i = 0; i < ((length > newSize) ? newSize : length); i++)
        temp[i] = content[i];
    temp[newSize] = '\0';
    delete[] content;
    content = temp;

}

const bool isLetter(const char c){ return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

char toBase10(const char *byte){ return (byte[0] - '0') * 16 + byte[1] - '0'; }
const char *toBase16(const unsigned char byte){

    const char *DIGITS = "0123456789ABCDEF";
    const size_t base = 16;
    char *result = new char[3];
    result[0] = DIGITS[byte / base];
    result[1] = DIGITS[byte % base];
    result[2] = '\0';
    return result;

}

HexViewer::HexViewer(char *path){

    this -> path = new char[strlen(path) + 1];
    strcpy(this -> path, path);
    try{ this -> loadBytes(); }
    catch(const int e){
        
        cout << ((e == -1) ? "Could not open file"
            : (e == -2) ? "Could not close file"
            : "Unknown error") << '\n';
        this -> failed = true;
        return;
    
    }
    this -> failed = false;
    cout << "File loaded successfully! Size: " << this -> contentSize << " bytes\n";

}

HexViewer::~HexViewer(){

    delete[] this -> path;
    delete[] this -> content;

}

const bool HexViewer::fail(){ return this -> failed; }

void HexViewer::save(){

    ofstream out(this -> path, ios::out | ios::binary);
    if(!out) throw FILE_CANNOT_OPEN;
    
    out.write(this -> content, this -> contentSize);

    out.close();
    if(!out.good()) throw FILE_COULD_NOT_CLOSE;

}

void HexViewer::saveAs(const char *newFileName){

    ofstream out(newFileName, ios::binary);
    if(!out) throw FILE_CANNOT_OPEN;

    out.write(this -> content, this -> contentSize);

    out.close();
    if(!out.good()) throw FILE_COULD_NOT_CLOSE;

}

void HexViewer::loadBytes(){

    ifstream in(this -> path, ios::binary);
    if(!in) throw FILE_CANNOT_OPEN;

    this -> contentSize = getFileSize(in);
    this -> content = new char[this -> contentSize + 1];

    in.read((char *) this -> content, this -> contentSize);
    this -> content[this -> contentSize] = '\0';

    in.close();

    if(!in.good()) throw FILE_COULD_NOT_CLOSE;

}


void HexViewer::add(const char *byte){

    resize(this -> content, ++this -> contentSize);
    this -> content[this -> contentSize - 1] = toBase10(byte);

}

void HexViewer::remove(){ resize(this -> content, --this -> contentSize); }
void HexViewer::changeByte(unsigned index, const char *byte){ this -> content[index] = toBase10(byte); }

void HexViewer::printContent(){
    
    const size_t LINELENGTH = 10;
    const size_t WIDTH = 2;
    size_t counter = 0;
    char prefix = '\0';

    for(size_t i = 0; i < this -> contentSize; i++){

        char c = this -> content[i];
        cout << prefix << toBase16(c);
        prefix = ' ';
        if(++counter % LINELENGTH == 0){ cout << '\n'; prefix = '\0'; }

    }
    
    cout << '\n';

    for(size_t i = 0; i < this -> contentSize; i++)
        cout << (isLetter(this -> content[i]) ? this -> content[i] : '.');
    
    cout << '\n';

}

const bool HexViewer::menu(){

    cout << ">";
    char command[100];
    cin.getline(command, 100);

    if(strstr(command, "view") != NULL){ this -> printContent(); return 1; }
    else if(strstr(command, "remove") != NULL){ this -> remove(); return 1; }
    else if(strstr(command, "add") != NULL){
        
        char byte[2]{ command[4], command[5] };
        this -> add(byte);
        return 1;
        
    }
    else if(strstr(command, "change") != NULL){
        
        size_t index = 0;
        size_t i;
        for(i = 7; i < strlen(command) && command[i] != ' '; i++)
            index = index * 10 + command[i] - '0';
        char byte[2];
        byte[0] = command[strlen(command) - 2];
        byte[1] = command[strlen(command) - 1];
        this -> changeByte(index, byte);
        cout << "Operation successfully executed!\n";
        return 1;
        
    }
    else if(strstr(command, "save as") != NULL){
        
        char *newName = new char[50];
        for(size_t i = 0; i < strlen(command); i++)
            newName[i] = command[i + 8];
        
        try{
            
            this -> saveAs(newName);
            cout << "File successfully saved\n";
            
        }
        catch(const int e){
            
            cout << (e == FILE_COULD_NOT_CLOSE ? "File was not able to close"
                : e == FILE_CANNOT_OPEN ? "File was not able to open"
                : "Unknown error") << '\n';
            
        }

        return 0;
        
    }
    else if(strstr(command, "save") != NULL){
        
        try{
            
            this -> save();
            cout << "File successfully saved\n";
            
        }
        catch(const int e){
            
            cout << (e == FILE_COULD_NOT_CLOSE ? "File was not able to close"
                : e == FILE_CANNOT_OPEN ? "File was not able to open"
                : "Unknown error") << '\n';
            
        }
        
        return 0;
    
    }

    return 1;

}