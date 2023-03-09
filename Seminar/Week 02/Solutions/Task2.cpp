#include <iostream>
#include <cstring>
#include <fstream>

using std::min;
using std::ios;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

const char *name = "MyData.dat";

size_t getFileSize(ifstream &);
void addByte(unsigned char *&, size_t &, const char *);
void removeLastByte(unsigned char *&, size_t &);
void changeByte(unsigned char * const &, const size_t &, const size_t &, const char * const &);
void print(const unsigned char * const &, const size_t &);
void save(const unsigned char * const &, const size_t &);
void saveAs(const char * const &, const unsigned char * const &, const size_t &);

int main(){

	ifstream file(name, ios::binary);

	if(!file.is_open()){

		cout << "Error\n";
		return -1;

	}

	size_t size = getFileSize(file);
	unsigned char *data = new unsigned char[size];

	file.read((char *)data, size);

	print(data, size);
	addByte(data, size, "FF");
	print(data, size);

	removeLastByte(data, size);
	print(data, size);

	changeByte(data, size, 3, "63");
	print(data, size);

	saveAs("newData.dat", data, size);

	delete[] data;

}

size_t getFileSize(ifstream &f){

	size_t currentPos = f.tellg();
	f.seekg(0, ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size;

}

void resize(unsigned char *&data, size_t &size, const size_t &newSize){

	unsigned char *newDataArr = new unsigned char[newSize];
	
	size_t minSize = min(size, newSize);
	for(size_t i = 0; i < minSize; i++)
		newDataArr[i] = data[i];

	delete[] data;
	data = newDataArr;
	size = newSize;

}

char convertSymbolToNumber(const char &symbol){

	if(symbol >= '0' && symbol <= '9') return symbol - '0';
	else if(symbol >= 'A' && symbol <= 'Z') return symbol - 'A' + 10;
	return '\0';

}

void addByte(unsigned char *&data, size_t &size, const char* byteStr){

	if(strlen(byteStr) != 2) return;

	unsigned char currentByte = 16 * convertSymbolToNumber(byteStr[0]) + convertSymbolToNumber(byteStr[1]);

	resize(data, size, size + 1);
	data[size - 1] = currentByte;

}

void removeLastByte(unsigned char *&data, size_t &size){

	if(size == 0) return;
	resize(data, size, size - 1);

}

void changeByte(unsigned char * const &data, const size_t &size, const size_t &index, const char * const &byteStr){
	
	if(index >= size || strlen(byteStr) != 2) return;

	char currentByte = convertSymbolToNumber(byteStr[1]) + 16 * convertSymbolToNumber(byteStr[0]);
	data[index] = currentByte;

}

void convertToHex(const unsigned char &byte, char * const &byteHex){

	char symbols[] = { '0','1', '2', '3', '4', '5', '6','7',
					  '8','9', 'A', 'B', 'C', 'D', 'E', 'F' };

	byteHex[2] = '\0';
	byteHex[1] = symbols[byte % 16];
	byteHex[0] = symbols[(byte / 16) % 16];

}

bool isLetter(const char &ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void print(const unsigned char * const &data, const size_t &size){

	char byteHex[3];

	for(size_t i = 0; i < size; ++i){

		convertToHex(data[i], byteHex);
		cout << byteHex << ' ';

	}

	cout << '\n';
	
	for(size_t i = 0; i < size; ++i){

		if(isLetter(data[i])) cout << data[i];
		else cout << '.';
		cout << ' ';

	}

	cout << '\n';

}

void save(const unsigned char * const &data, const size_t &size){

	ofstream file(name, ios::binary);

	if(!file.is_open()){
		
		cout << "Couldn't save\n";
		return;
	
	}

	file.write((const char *)data, size);

	file.close();

}

void saveAs(const char * const &fileName, const unsigned char * const &data, const size_t &size){

	ofstream file(fileName, ios::binary);

	if(!file.is_open()){
		
		cout << "Couldn't save\n";
		return;
	
	}

	file.write((const char *)data, size);

	file.close();

}