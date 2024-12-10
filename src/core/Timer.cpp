//
// Created by cmartin on 2024/12/10.
//

#include "Timer.h"

Timer::Timer()
{
    reset();
}

void Timer::reset()
{
    m_last_time = std::chrono::high_resolution_clock::now();
}

float Timer::get_delta_time()
{
    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> delta = current_time - m_last_time;
    m_last_time = current_time;
    return delta.count();
}