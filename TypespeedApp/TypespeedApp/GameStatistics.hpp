#ifndef GAMESTATISTICS_HPP
#define GAMESTATISTICS_HPP

#include <string> 

using namespace std;

class GameStatistics {
private:
	int numberOfWords, numberOfCorrectWords;
	int numberOfChars, numberOfCorrectChars;
	int timeOfRunningSeconds;
public:
	void increaseNumberOfWords();
	void increaseNumberOfCorrectWords();
	void increaseNumberOfChars(string word);
	void increaseNumberOfCorrectChars(string word);

	void printResults();
	void printStatistics(double wordSuccesRate, double charSuccesRate);
	void calculateWordAndCharSuccessRate(double &wordSuccesRate, double &charSuccesRate);
	void printSpeedSuccessMessage();
	void calculateTypingSpeed(double &wordsPerMinute, double &charsPerMinute);
	void printCharSuccesMessage(double charSuccesRate);
	void printWordSuccesMessage(double wordSuccesRate);

	void setTimeOfRunningInSeconds(int seconds);
};

#endif // !GAMESTATISTICS_HPP
