#ifndef WORDSGENERATOR_HPP
#define WORDSGENERATOR_HPP

#include <string>

using namespace std;

class WordsGenerator {
public:
	virtual string generateWord() = 0;
	virtual bool isGeneratorAvailable() = 0;
};

#endif // !WORDSGENERATOR_HPP
