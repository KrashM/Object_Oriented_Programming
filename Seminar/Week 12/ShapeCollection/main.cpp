#include "ShapeCollection.hpp"
#include <iostream>

int main(){

	ShapeCollection s;

	s.addCircle(3, 4, 1);
	s.addTriangle(1, 2, 9, 4, 0, 0);
	s.addRectangle(1, 1, 9, 9);

	std::cout << s.getIfPointInShapeByIndex(0, 3, 4.5) << '\n';
	std::cout << s.getAreaOfFigureByIndex(2) << '\n';

}
