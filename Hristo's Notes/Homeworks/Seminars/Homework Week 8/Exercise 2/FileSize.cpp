#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::ios;

size_t getFileSize(ifstream &in){

	in.seekg(ios::beg, ios::end);
	return in.tellg();

}

int main(){

    ifstream in("file.txt");
    size_t size = getFileSize(in);
    in.close();

    cout << size << '\n';

}