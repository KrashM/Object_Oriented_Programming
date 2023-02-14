#include <fstream>

using std::ofstream;
using std::ios;

size_t getFileSize(ofstream &out){

    size_t currentPosition = out.tellp();
	out.seekp(ios::beg, ios::end);
    size_t size = out.tellp();

    out.seekp(currentPosition);

	return size;

}

void changeContent(ofstream &out){

    out.open("file.txt");

    size_t size = getFileSize(out);

    out << "Hello world";
    // for(int i = 0; i < size; i++){

    //     out.seekp(i);
    //     out.put('H');

    // }

    out.close();

}

int main(){

    ofstream out;
    changeContent(out);

}