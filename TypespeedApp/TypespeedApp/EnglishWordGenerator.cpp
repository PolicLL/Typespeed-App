#include <iostream>
#include "EnglishWordGenerator.hpp"
#include "FileReader.hpp"
#include "EmptyGeneratorListException.hpp"

using namespace std;

EnglishWordGenerator::EnglishWordGenerator(string wordsFilePath){
	fillWordsList(wordsFilePath);
}

void EnglishWordGenerator::fillWordsList(string wordsFilePath){
	if(fileReader.doesFileExists(wordsFilePath))
		words = fileReader.readWordsFromFile(wordsFilePath);
}

string EnglishWordGenerator::generateWord(){
	if (words.size() == 0)
		return "";

	int index = randomValuesGenerator.getRandomNumber(0, words.size() - 1);
	return words.at(index);
}

bool EnglishWordGenerator::isGeneratorAvailable(){
	return (words.size() != 0);
}





