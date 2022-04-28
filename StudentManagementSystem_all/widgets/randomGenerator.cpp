#include "randomGenerator.h"
#include<chrono>

RandomGenerator::RandomGenerator(uint32_t seedValue)
    :m_engine(new std::default_random_engine(seedValue))
{
    
}

int RandomGenerator::bounded(int highest)
{
    std::uniform_int_distribution<int> intDis(0, highest-1);
    return intDis(*m_engine);
}

int RandomGenerator::bounded(int lowest, int highest)
{
    std::uniform_int_distribution<int> intDis(lowest, highest-1);
    return intDis(*m_engine);
}

RandomGenerator* RandomGenerator::global()
{
    static RandomGenerator* instance = nullptr;
    if (instance == nullptr)
    {
        instance = new RandomGenerator((uint32_t)std::chrono::system_clock::now().time_since_epoch().count());
    }
    return instance;
}
