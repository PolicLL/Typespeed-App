#include <iostream>
#include <chrono>
#include "TimeManager.hpp"

using namespace std;

void TimeManager::setStartTime() {
	startTime = chrono::steady_clock::now();
}

void TimeManager::setCurrentTime() {
	currentTime = chrono::steady_clock::now();
}

int TimeManager::calculateElapsedTimeInSeconds() {
	setCurrentTime();
	elapsed = currentTime - startTime;
	return elapsed.count();
}

void TimeManager::printRemainingTime(int timeOfRunning) {
	cout << (int)timeOfRunning - elapsed.count() << " seconds left." << endl;
}
