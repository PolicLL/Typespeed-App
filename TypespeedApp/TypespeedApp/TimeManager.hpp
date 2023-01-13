#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP

#include <iostream>
#include <chrono>

using namespace std;

class TimeManager {
private:
	chrono::steady_clock::time_point startTime , currentTime;
	chrono::duration<double> elapsed;
public:
	void setStartTime();
	void setCurrentTime();
	int calculateElapsedTimeInSeconds();
	void printRemainingTime(int timeOfRunning);
};

#endif // !TIMEMANAGER_HPP
