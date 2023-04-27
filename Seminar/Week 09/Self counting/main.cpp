#include "SelfCounting.hpp"
#include <iostream>

int main(){

	SelfCounting s(4);
	SelfCounting s2(30);

	{
		SelfCounting s3(232);

		std::cout << SelfCounting::getCreatedCount() << " " << SelfCounting::getLiveObjectsCount() << '\n';
	}
	std::cout << SelfCounting::getCreatedCount() << " " << SelfCounting::getLiveObjectsCount() << '\n';

}