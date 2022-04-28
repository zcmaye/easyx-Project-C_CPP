#pragma once
#include<chrono>
using namespace std::chrono;
/*定时器*/
class Timer
{
public:
	Timer(int64_t ms = 0);
	void startTimer();
	bool timeout();
	void setTime(int64_t ms);
	void killTimer();
public:
	//静态定时器
	static bool startTimer(int64_t ms, int id);
	//定时器的最大ID
	inline static size_t maxTimerID() { return 20; };
private:
    int64_t m_ms;	//延迟毫秒数
	time_point<high_resolution_clock> m_startime;
	time_point<high_resolution_clock> m_endtime;

	bool m_threadIsRun;	//控制线程运行
};

/*时间间隔（计算运行时间）*/
class ElapsedTimer
{
public:
    ElapsedTimer();
    void reset();
    //默认输出毫秒
    int64_t elapsed() const;
    //微秒
    int64_t elapsed_micro() const;
    //纳秒
    int64_t elapsed_nano() const;
    //秒
    int64_t elapsed_seconds() const;
    //分
    int64_t elapsed_minutes() const;
    //时
    int64_t elapsed_hours() const;
private:
    time_point<high_resolution_clock> m_begin;
};

