#include "Timer.h"
#include<thread>
#include<iostream>
Timer::Timer(int64_t ms)
	:m_ms(ms), m_threadIsRun(false)
{
}

void Timer::startTimer()
{
	m_startime = high_resolution_clock::now();

	m_threadIsRun = true;
	static std::thread thr;
	thr = std::thread([this]() 
		{
			while (m_threadIsRun)
			{
				m_endtime = high_resolution_clock::now();
				std::this_thread::sleep_for(std::chrono::milliseconds(2));
			}	
		});
}

bool Timer::timeout()
{
	if (m_endtime - m_startime >= milliseconds(m_ms))
	{
		m_startime = m_endtime;
		return true;
	}
	return false;
}

void Timer::setTime(int64_t ms)
{
	m_ms = ms;
}

void Timer::killTimer()
{
	m_threadIsRun = false;
}

bool Timer::startTimer(int64_t ms, int id)
{
	static int64_t start[21] = { 0 };
	int64_t end = clock();
	if (end - start[id] >= ms)
	{
		start[id] = end;
		return true;
	}
	return false;
}


/*@时间间隔*/
ElapsedTimer::ElapsedTimer() : m_begin(high_resolution_clock::now()) {}
void ElapsedTimer::reset() { m_begin = high_resolution_clock::now(); }
//默认输出毫秒
int64_t ElapsedTimer::elapsed() const
{
    return duration_cast<milliseconds>(high_resolution_clock::now() - m_begin).count();
}
//微秒
int64_t ElapsedTimer::elapsed_micro() const
{
    return duration_cast<microseconds>(high_resolution_clock::now() - m_begin).count();
}
//纳秒
int64_t ElapsedTimer::elapsed_nano() const
{
    return duration_cast<nanoseconds>(high_resolution_clock::now() - m_begin).count();
}
//秒
int64_t ElapsedTimer::elapsed_seconds() const
{
    return duration_cast<seconds>(high_resolution_clock::now() - m_begin).count();
}
//分
int64_t ElapsedTimer::elapsed_minutes() const
{
    return duration_cast<minutes>(high_resolution_clock::now() - m_begin).count();
}
//时
int64_t ElapsedTimer::elapsed_hours() const
{
    return duration_cast<hours>(high_resolution_clock::now() - m_begin).count();
}