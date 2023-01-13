#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <algorithm>

#include <chrono>
#include <cctype>

#include "FileReader.hpp"
#include "EnglishWordGenerator.hpp"
#include "Game.hpp"

using namespace std;

int main() {

	string wordsFilePath = "words.txt";

	Game game(wordsFilePath);

	game.startGame(20);

	return 0;
}

