#include <iostream>
#include <fstream>
#include <algorithm>

#include "FileReader.hpp"

using namespace std;

vector<string> FileReader::readWordsFromFile(string path) {
	ifstream  inputStream(path);
	vector<string> words;

	if (!inputStream) {
		cout << "Error opening file" << endl;
		return words;
	}

	insertValuesFromFileToVector(inputStream, words);
	return words;
}

void FileReader::insertValuesFromFileToVector(ifstream &inputStream, vector<string> &words){
	string line;

	while (getline(inputStream, line))
		words.push_back(line);
}

bool FileReader::doesFileExists(string path){
	ifstream file(path);
	return file.good();
}

