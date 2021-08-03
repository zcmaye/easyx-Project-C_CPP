#include "../include/Timer.h"
#include<thread>
#include<iostream>
Timer::Timer(clock_t ms)
	:m_ms(ms),m_startime(0),m_endtime(0), m_threadIsRun(false)
{
}

void Timer::startTimer()
{
	m_threadIsRun = true;
	static std::thread thr;
	thr = std::thread([this]() 
		{
			while (m_threadIsRun)
			{
				m_endtime = clock();
				std::this_thread::sleep_for(std::chrono::milliseconds(2));
			}	
		});
}

bool Timer::timeOut()
{
	if (m_endtime - m_startime >= m_ms)
	{
		m_startime = m_endtime;
		return true;
	}
	return false;
}

void Timer::setTime(clock_t ms)
{
	m_ms = ms;
}

void Timer::killTimer()
{
	m_threadIsRun = false;
}

bool Timer::startTimer(clock_t ms, int id)
{
	static clock_t start[21] = { 0 };
	clock_t end = clock();
	if (end - start[id] >= ms)
	{
		start[id] = end;
		return true;
	}
	return false;
}
