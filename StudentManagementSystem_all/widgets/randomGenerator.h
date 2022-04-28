#pragma once
#include<cstdint>
#include<random>
/*随机数生成*/
class RandomGenerator
{
public:
	RandomGenerator(uint32_t seedValue = 1);
	//生成[0,highest)区间的数
	int bounded(int highest);					
	//生成[lowest,highest)区间的数
	int bounded(int lowest, int highest);
	static RandomGenerator* global();
private:
	std::default_random_engine * m_engine;
};





