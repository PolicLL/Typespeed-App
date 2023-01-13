#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>
#include <vector>

using namespace std;

class FileReader {
public:
	void insertValuesFromFileToVector(ifstream &inputStream, vector<string> &words);
	bool doesFileExists(string path);
	vector<string> readWordsFromFile(string path);
};

#endif // !FILEREADER_HPP
