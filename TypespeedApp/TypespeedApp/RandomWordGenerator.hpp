
#ifndef RANDOMWORDGENERATOR_H
#define RANDOMWORDGENERATOR_H

#include <string>
#include "WordsGenerator.hpp"
#include "RandomValuesGenerator.hpp"

using namespace std;

class RandomWordGenerator : public WordsGenerator {
private:
	RandomValuesGenerator randomValuesGenerator;
	const int DEFAULT_MIN_WORD_LENGTH = 3;
	const int DEFAULT_MAX_WORD_LENGTH = 10;
public: 
	string generateWord();
	string generateWordOfLength(int length);
	string generateWord(int minLength, int maxLength);
	bool isGeneratorAvailable();

};

#endif // !RANDOMWORDGENERATOR_H
