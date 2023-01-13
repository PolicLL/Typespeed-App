#ifndef ENGLISHWORDGENERATOR_HPP
#define ENGLISHWORDGENERATOR_HPP

#include <string>
#include <vector>
#include "WordsGenerator.hpp"
#include "RandomValuesGenerator.hpp"
#include "FileReader.hpp"

using namespace std;

class EnglishWordGenerator : public WordsGenerator {
private:
	RandomValuesGenerator randomValuesGenerator;
	FileReader fileReader;
	vector<string> words;
public:
	EnglishWordGenerator(string wordsFilePath);
	void fillWordsList(string wordsFilePath);
	string generateWord();
	bool isGeneratorAvailable();

};

#endif // !ENGLISHWORDGENERATOR_HPP
