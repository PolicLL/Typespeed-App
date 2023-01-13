#include "RandomValuesGenerator.hpp"

#include <random>

using namespace std;

int RandomValuesGenerator::getRandomNumber(int start, int end){
	std::random_device randomDevice; // obtain a random number from hardware
	std::mt19937 generator(randomDevice()); // seed the generator
	std::uniform_int_distribution<> distribution(start, end); // define the range

	return distribution(generator);
}

char RandomValuesGenerator::getRandomLetter(){
	return (char)getRandomNumber(97, 122);
}


