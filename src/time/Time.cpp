#include "Time.h"

time_t Time::milliseconds()
{
    struct timeval timeNow;

    gettimeofday(&timeNow, nullptr);
    time_t msecsTime = (timeNow.tv_sec * 1000) + (timeNow.tv_usec / 1000);
    return msecsTime;
}