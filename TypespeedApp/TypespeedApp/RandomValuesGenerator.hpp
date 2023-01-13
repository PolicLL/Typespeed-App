#ifndef RANDOMVALUESGENERATOR_HPP
#define RANDOMVALUESGENERATOR_HPP

#include <string>
#include "WordsGenerator.hpp"

using namespace std;

class RandomValuesGenerator {
public:
	int getRandomNumber(int start, int end);
	char getRandomLetter();
};

#endif // !RANDOMVALUESGENERATOR_HPP
