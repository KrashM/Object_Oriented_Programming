#include "ShapeCollection/ShapeCollection.hpp"
#include <iostream>

int main(){

	ShapeCollection s;

	s.addCircle(3, 4, 1);
	s.addTriangle(1, 2, 9, 4, 0, 0);
	s.addRectangle(1, 1, 9, 9);

	std::cout << s.getIfPointInShapeByIndex(0, 3, 4.5) << '\n';
	std::cout << s.getAreaOfFigureByIndex(2) << '\n';

	s[0] -> intersectsWith(s[1]);
	s[1] -> intersectsWith(s[2]);
	s[2] -> intersectsWith(s[1]);

}
