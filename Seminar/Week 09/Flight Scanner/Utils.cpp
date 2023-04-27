#include "Utils.hpp"
#include <iostream>
#include <cstdint>

//we don't make them static, because we want to use the in other cpp files.

bool isLower(char const ch){ return ch >= 'a' && ch <= 'z'; }
bool isUpper(char const ch){ return ch >= 'A' && ch <= 'Z'; }
bool isLetter(char const ch){ return isLower(ch) || isUpper(ch); }

void toUpper(char *str){

	if(!str) throw std::invalid_argument("The given string does not exist");

	static const uint32_t diff = 'a' - 'A';

	while(*str){

		if(!isLetter(*str)) throw std::bad_cast();
		if(isLower(*str)) *str = *str - diff;
		str++;

	}

}

uint32_t charToDigit(char const ch){

	if(ch < '0' || ch > '9') throw std::bad_cast();
	return ch - '0';

}

uint32_t convertToNumber(char const *str){

	if(!str) throw std::invalid_argument("The given string does not exist");

	uint32_t result = 0;

	while(*str){

		result *= 10;
		result += charToDigit(*str);
		str++;

	}

	return result;

}