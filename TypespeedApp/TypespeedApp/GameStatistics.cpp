#include "GameStatistics.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

void GameStatistics::increaseNumberOfWords() { ++numberOfWords; }

void GameStatistics::increaseNumberOfCorrectWords() { ++numberOfCorrectWords; }

void GameStatistics::increaseNumberOfChars(string word) { numberOfChars += word.length(); }

void GameStatistics::increaseNumberOfCorrectChars(string word) { numberOfCorrectChars += word.length(); }

void GameStatistics::printResults(){
	double wordSuccesRate, charSuccesRate;

	calculateWordAndCharSuccessRate(wordSuccesRate, charSuccesRate);
	printStatistics(wordSuccesRate, charSuccesRate);
}

void GameStatistics::calculateWordAndCharSuccessRate(double &wordSuccesRate, double &charSuccesRate){
	wordSuccesRate = ((double)numberOfCorrectWords / (double)numberOfWords) * 100;
	charSuccesRate = ((double)numberOfCorrectChars / (double)numberOfChars) * 100;
}

void GameStatistics::printStatistics(double wordSuccesRate, double charSuccesRate) {
	printWordSuccesMessage(wordSuccesRate);
	printCharSuccesMessage(charSuccesRate);
	printSpeedSuccessMessage();
}

void GameStatistics::printWordSuccesMessage(double wordSuccesRate) {
	printf("\nNumber of words : %d | Number of correctly inserted words : %d | Success rate : %.2f"
		, numberOfWords, numberOfCorrectWords, wordSuccesRate);

	cout << " % " << endl;
}

void GameStatistics::printCharSuccesMessage(double charSuccesRate) {
	printf("Number of chars : %d | Number of correctly inserted chars : %d | Success rate : %.2f"
		, numberOfChars, numberOfCorrectChars, charSuccesRate);

	cout << " % " << endl;
}

void GameStatistics::printSpeedSuccessMessage() {

	double wordsPerMinute, charsPerMinute;
	calculateTypingSpeed(wordsPerMinute, charsPerMinute);

	printf("SPEED : You wrote %.2f words per minute and %.2f chars per minute. \n", wordsPerMinute, charsPerMinute);
}

void GameStatistics::calculateTypingSpeed(double &wordsPerMinute, double &charsPerMinute) {
	wordsPerMinute = (60 * numberOfCorrectWords) / timeOfRunningSeconds;
	charsPerMinute = (60 * numberOfCorrectChars) / timeOfRunningSeconds;
}

void GameStatistics::setTimeOfRunningInSeconds(int seconds){
	timeOfRunningSeconds = seconds;
}
