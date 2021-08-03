#pragma once
#include<ctime>
class Timer
{
public:
	Timer(clock_t ms = 0);
	void startTimer();
	bool timeOut();
	void setTime(clock_t ms);
	void killTimer();
public:
	//静态定时器
	static bool startTimer(clock_t ms, int id);
	//定时器的最大ID
	inline static size_t maxTimerID() { return 20; };
private:
	clock_t m_ms;	//延迟毫秒数
	clock_t m_startime;
	clock_t m_endtime;

	bool m_threadIsRun;	//控制线程运行
};

