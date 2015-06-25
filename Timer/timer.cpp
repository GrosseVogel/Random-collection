#include "timer.h"

cusTimer::cusTimer()
{
	running = false;
	accumulatedTime = 0.0;
}

double cusTimer::get()
{
	double result;

	if (running)
		result = (std::clock() - begin) / (float)CLOCKS_PER_SEC + accumulatedTime;
	else
		result = accumulatedTime;

	return result;
}

void cusTimer::reset()
{
	begin = clock();
	accumulatedTime = 0.0;
}

void cusTimer::start()
{
	if (!running)
	{
		begin = clock();
		running = true;
	}
}

void cusTimer::stop()
{
	double temp = get();

	if (running)
	{
		accumulatedTime = temp;
		running = false;
	}
}

bool cusTimer::hasPeriodPassed(double period)
{
	if (get() > period)
		return true;
	
	return false;
}
