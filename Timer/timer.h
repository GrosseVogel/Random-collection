#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>

class cusTimer
{
private:
	std::clock_t begin;
	bool running;
	double accumulatedTime;
public:
	cusTimer();
	double get();
	void reset();
	void start();
	void stop();
	bool hasPeriodPassed(double period);
};

#endif

