#include <iostream>
#include <fstream>
#include <cstring>

using std::ios;
using std::cout;
using std::ifstream;

struct Student{

	char name[30];
	int age;
	int fn;

};

size_t getFileSize(ifstream &f){

	size_t currentPos = f.tellg();
	f.seekg(0, ios::end);
	size_t size = f.tellg();
	
	f.seekg(currentPos);
	return size;

}

void readFromFile(Student *&ptr, size_t &studentsCount, ifstream &f){

	size_t sizeOfFile = getFileSize(f);
	studentsCount = sizeOfFile / sizeof(Student);
	ptr = new Student[studentsCount];
	f.read((char*)ptr, sizeOfFile);

}


int main(){

	Student* arr;
	size_t count;
	ifstream file("students.dat", ios::binary);
			
	if(!file.is_open()){

		cout << "Error while opening the file!\n";
		return -1;

	}

	readFromFile(arr, count, file);

	for (int i = 0; i < count; i++)
		cout << "Name: " << arr[i].name << ", age: " << arr[i].age << ", fn: " << arr[i].fn << '\n';

	delete[] arr;

}
