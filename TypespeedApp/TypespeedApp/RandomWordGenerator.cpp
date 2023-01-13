#include "RandomWordGenerator.hpp"

#include <random>

using namespace std;

string RandomWordGenerator::generateWord() {
	return generateWord(DEFAULT_MIN_WORD_LENGTH , DEFAULT_MAX_WORD_LENGTH);
}

string RandomWordGenerator::generateWordOfLength(int length) {
	string tempString;

	for (int i = 0; i < length; ++i) 
		tempString += randomValuesGenerator.getRandomLetter();

	return tempString;
}

string RandomWordGenerator::generateWord(int minLength, int maxLength) {
	int lengthOfString = randomValuesGenerator.getRandomNumber(minLength, maxLength);
	string tempString;

	for (int i = 0; i < lengthOfString; ++i)
		tempString += randomValuesGenerator.getRandomLetter();

	return tempString;
}

bool RandomWordGenerator::isGeneratorAvailable(){
	return true;
}

