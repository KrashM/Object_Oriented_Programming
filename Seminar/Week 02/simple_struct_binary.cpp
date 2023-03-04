#include <iostream>
#include <fstream>

using std::ios;
using std::cout;
using std::ofstream;
using std::ifstream;

struct Test{

	bool b;
	int x;

};

int main(){

	{   // write

		Test t = { true, 45 };
		ofstream file("testObj.bat", ios::binary);
		
		if(!file.is_open()) return -1;

		file.write((const char*)&t, sizeof(t));

		file.close();

	}

	{   // read

		Test t;
		ifstream file("testObj.bat", ios::binary);
		
		if(!file.is_open()) return -1;

		file.read((char*)&t, sizeof(t));

		cout << t.b << " " << t.x << '\n';

		file.close();

	}

}
