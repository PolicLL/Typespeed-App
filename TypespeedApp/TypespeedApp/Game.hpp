#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include <chrono>

#include "EnglishWordGenerator.hpp"
#include "EmptyGeneratorListException.hpp"
#include "GameStatistics.hpp"
#include "ColorText.hpp"
#include "TimeManager.hpp"


using namespace std;

class Game {
private:
	const int ENGLISH_WORDS_OPTION = 1;
	const int RANDOM_LETTER_WORDS_OPTION = 2;

	WordsGenerator* wordsGenerator;
	GameStatistics gameStatistics;
	ColorText colorText;
	TimeManager timeManager;
	
public:
	void startGame(int timeOfRunningInSeconds);
	void playTheRound(int timeOfRunningInSeconds);
	void setInitialValues(int timeOfRunningInSeconds);
	bool isTimeOver(int timeOfRunningInSeconds);
	void printResults();
	void enterString(int timeOfRunningInSeconds);

	void updateGameStatistics(std::string &generatedString);

	void checkInsertedWord(std::string &output, std::string &generatedString);

	void updateScreenAndStatisticsForCorrectInput(std::string & generatedString);

	string insertWord(std::string &generatedString);

	void printCorrectMessage();
	void printWrongMessage();

	
	int prepareTheGame();
	int chooseGameOption();
	void resetCinComand();
	void displayGameOptionsMessage();

	Game(string wordsFilePath);
	void tryPreparingEnglishWords(string wordsFilePath);
	void handleEmptyGeneratorListException(EmptyGeneratorListException &exception);

	~Game();
};

#endif // !GAME_HPP
