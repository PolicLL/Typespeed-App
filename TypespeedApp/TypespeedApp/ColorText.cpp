#include "ColorText.hpp"

#include <string>
#include <iostream>

using namespace std;

void ColorText::printTextInGreen(string text){
	cout << GREEN + text << endl;
	setTextToDefaultColor();
}

void ColorText::printTextInRed(string text){
	cout << RED + text << endl;
	setTextToDefaultColor();
}

void ColorText::setTextToDefaultColor(){
	cout << DEFAULT;
}
