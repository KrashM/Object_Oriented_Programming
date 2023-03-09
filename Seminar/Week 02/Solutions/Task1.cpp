#include <iostream>
#include <fstream>
#include <cstring>

using std::ios;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

const size_t capacity = 1024;

struct StudentRecord{

	char firstName[capacity];
	char lastName[capacity];
	char fnRaw[capacity];
	char email[capacity];

	int fn;

};

struct StudentCollection{

	StudentRecord *data;
	size_t studentsCount;

};

size_t getLinesCount(ifstream &file){

	size_t count = 0;
    char buff[capacity];

	while(!file.eof()){

		file.getline(buff, capacity);
		count++;

	}
	
	file.seekg(0, ios::beg);

	return count;

}

void parseField(char * const &dest, const char *&source){

    size_t index = 0;

	while(source[index] != ',' && source[index] != '\0'){

        dest[index] = source[index];
        index++;

    }

	source += index + 1;
	dest[index] = '\0';

}

void parseFn(StudentRecord &currentStudent){

	if(strlen(currentStudent.fnRaw) < 5) return;
	currentStudent.fn = atoi(currentStudent.fnRaw + 5);

}

void parseStudent(StudentRecord &currentStudent, const char *line){

	parseField(currentStudent.firstName, line);
	parseField(currentStudent.lastName, line);
	parseField(currentStudent.fnRaw, line);
	parseField(currentStudent.email, line);
	parseFn(currentStudent);

}

StudentRecord *find(const StudentCollection &collection, const int &fn){

    for(size_t i = 0; i < collection.studentsCount; ++i)
        if(collection.data[i].fn == fn) return collection.data + i;
    return nullptr;

}

void printStudent(const StudentRecord &st){

	cout << "First name: " << st.firstName
        << ", second name: " << st.lastName
        << ", number: " << st.fn
        << ", email: " << st.email
        << '\n';

}

void initStudentCollection(StudentCollection &collection, const char * const &fileName){
	
	ifstream file(fileName);

	if(!file.is_open()){

		cout << "Error while reading from file!" << '\n';

		collection.studentsCount = 0;
		collection.data = nullptr;

		return;

	}

	size_t linesCount = getLinesCount(file);
	size_t studentsCount = linesCount - 1;
	
	if(!studentsCount) return;
	
	collection.data = new StudentRecord[studentsCount];
	collection.studentsCount = studentsCount;

	char buff[capacity];
	file.getline(buff, capacity); // skip the header

	for(size_t i = 0; i < studentsCount; i++){

		file.getline(buff, capacity);
		parseStudent(collection.data[i], buff);

	}

}

void saveToFile(const char * const &fileName, const StudentCollection &collection){

	ofstream file(fileName);

	if(!file.is_open()) return;

	file << "Ime, Familiya, Fakulteten nomer, Imeyl adres" << '\n';

	for(int i = 0; i < collection.studentsCount; i++)
	    file << collection.data[i].firstName << ","
            << collection.data[i].lastName << ","
            << collection.data[i].fnRaw << ","
            << collection.data[i].email << '\n';

}

void menu(StudentCollection &collection){

    char command[capacity];
    char name[capacity];
    char str[capacity];
    int fn;

    do{

        cin >> command;

        if(!strcmp(command, "save")){

            cin >> name;
            saveToFile(name, collection);
            break;

        }

        if(!strcmp(command, "print")){

            cin >> fn;
            StudentRecord *querry = find(collection, fn);
            if(!querry) continue;
            printStudent(*querry);

        }

        if(!strcmp(command, "edit")){

            cin >> fn >> str;
            StudentRecord *querry = find(collection, fn);
            if(!querry) continue;
            strcpy(querry -> email, str);

        }

    }while(strcmp(command, "save"));

}

int main(){

	char fileName[capacity];

    cout << "Open File:\n>";
    cin >> fileName;
    cin.ignore();
    
	StudentCollection collection;
	initStudentCollection(collection, fileName);

	if(!collection.studentsCount){

	    std::cout << "Error! No students loaded!" << std::endl;
	    return -1;

	}

    menu(collection);
    
	delete[] collection.data;

}
