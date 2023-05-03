#include <vector>

#include "Duck.h"

int main()
{
	/*Animal a = Flier();
	a.print();
	Flier f;
	f.print();
	Swimmer s;
	s.print();
	Duck d("Ivan");
	d.print();*/
	/*Animal* obj = new Flier();
	obj->print();
	Flier* obj1 = new Duck("Ivan");
	obj1->print();
	Animal* duck = new Duck("Ivan");
	duck->print();*/
	/*std::vector<Animal*> v;
	v.push_back(new Animal());
	v.push_back(new Flier());
	v.push_back(new Swimmer());
	v.push_back(new Duck("Ivan"));
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->print();
		v[i]->serialize();
		v[i]->deserialize();
	}*/
	
	
	/*Animal** zoo = new Animal * [10];
	zoo[0] = new Animal();
	zoo[1] = new Flier();
	zoo[2] = new Swimmer();
	zoo[3] = new Duck("Ivan");

	for (int i = 0; i < 4; ++i)
	{
		delete zoo[i];
	}
	delete[] zoo;*/

	Animal* a = new Duck("Ivan");
	delete a;
}
