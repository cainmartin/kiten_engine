//
// Created by cmartin on 2024/12/10.
//

#ifndef KITEN_ENGINE_TIMER_H
#define KITEN_ENGINE_TIMER_H

#include <chrono>

class Timer
{
public:
    Timer();
    void reset();
    float get_delta_time();

private:
    std::chrono::high_resolution_clock::time_point m_last_time;
};


#endif //KITEN_ENGINE_TIMER_H
