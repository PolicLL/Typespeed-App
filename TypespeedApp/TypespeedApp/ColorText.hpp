#ifndef COLORTEXT_HPP
#define COLORTEXT_HPP

#include <string>

using namespace std;

class ColorText {
private:
	string GREEN = "\033[1;32m";
	string RED = "\033[1;31m";
	string DEFAULT = "\033[0m";

	void setTextToDefaultColor();
public:
	void printTextInGreen(string text);
	void printTextInRed(string text);
};

#endif // !COLORTEXT_HPP
