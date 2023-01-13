#include "Game.hpp"
#include <iostream>
#include <string>
#include <chrono>

#include "RandomWordGenerator.hpp"
#include "WordsGenerator.hpp"
#include "EmptyGeneratorListException.hpp"

using namespace std;

Game::Game(string wordsFilePath) {

	if (prepareTheGame() == ENGLISH_WORDS_OPTION) 
		tryPreparingEnglishWords(wordsFilePath);
	
	else wordsGenerator = new RandomWordGenerator();
}

// Preparing Game

int Game::prepareTheGame() {
	displayGameOptionsMessage();
	return chooseGameOption();
}

void Game::displayGameOptionsMessage() {
	cout << "You have 2 differente types of game." << endl;
	cout << "Type 1 : Only english words." << endl;
	cout << "Type 2 : Only random letter words." << endl;
}

int Game::chooseGameOption() {
	int type = 0;

	do {
		cout << "Choose one of the two types of game : ";
		cin >> type;

		if (!cin)
			resetCinComand();

	} while (type != 1 && type != 2);

	resetCinComand();


	return type;
}

void Game::resetCinComand() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Game::tryPreparingEnglishWords(string wordsFilePath)
{
	try {
		wordsGenerator = new EnglishWordGenerator(wordsFilePath);

		if (!wordsGenerator->isGeneratorAvailable()) 
			throw EmptyGeneratorListException();
	}
	catch (EmptyGeneratorListException exception) {
		handleEmptyGeneratorListException(exception);
	}
}

void Game::handleEmptyGeneratorListException(EmptyGeneratorListException &exception) {
	cout << exception.getMessage() << endl;
	wordsGenerator = new RandomWordGenerator();
}


// Starting Game

void Game::startGame(int timeOfRunningInSeconds){

	setInitialValues(timeOfRunningInSeconds);

	while (!isTimeOver(timeOfRunningInSeconds)) 
		playTheRound(timeOfRunningInSeconds);
	
	printResults();
}


void Game::setInitialValues(int timeOfRunningInSeconds) {
	timeManager.setStartTime();
	gameStatistics.setTimeOfRunningInSeconds(timeOfRunningInSeconds);
}

bool Game::isTimeOver(int timeOfRunningInSeconds) {
	return timeManager.calculateElapsedTimeInSeconds() > timeOfRunningInSeconds;
}

void Game::playTheRound(int timeOfRunningInSeconds) {
	enterString(timeOfRunningInSeconds);
	timeManager.printRemainingTime(timeOfRunningInSeconds);
}

void Game::enterString(int timeOfRunningInSeconds){
	string generatedString = wordsGenerator->generateWord();
	string output = insertWord(generatedString);

	if (isTimeOver(timeOfRunningInSeconds)) return;

	updateGameStatistics(generatedString);
	checkInsertedWord(output, generatedString);
}

string Game::insertWord(std::string &generatedString) {
	cout << "Type the string ( " << generatedString << " ) : ";
	string output;
	getline(cin, output);

	return output;
}

void Game::updateGameStatistics(std::string &generatedString) {
	gameStatistics.increaseNumberOfWords();
	gameStatistics.increaseNumberOfChars(generatedString);
}

void Game::checkInsertedWord(std::string &output, std::string &generatedString){
	if (output == generatedString) 
		updateScreenAndStatisticsForCorrectInput(generatedString);
	
	else printWrongMessage();
}

void Game::updateScreenAndStatisticsForCorrectInput(std::string & generatedString) {
	printCorrectMessage();
	gameStatistics.increaseNumberOfCorrectChars(generatedString);
	gameStatistics.increaseNumberOfCorrectWords();
}


void Game::printCorrectMessage(){
	colorText.printTextInGreen("Correct !");
}

void Game::printWrongMessage() {
	colorText.printTextInRed("Wrong ! ");
}

void Game::printResults() {
	gameStatistics.printResults();
}

Game::~Game(){
	delete(wordsGenerator);
}
