/**
 * timer.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include "timer.h"
#include <sys/time.h>
#include <stdio.h>

static struct timeval timer, now;
static int delay = -1;

// Initialize the timer with a specified value in milliseconds
void timerInit(int valueMilliSec)
{
    delay = valueMilliSec;
    gettimeofday(&timer, NULL);
}

// Destroy the timer (unset the delay value)
void timerDestroy()
{
    delay = -1;
}

// Update the timer with a new value in milliseconds
void timerUpdateTimer(int valueMilliSec)
{
    delay = valueMilliSec;
    gettimeofday(&timer, NULL);
}

// Get the time difference in milliseconds
int getTimeDiff()
{
    gettimeofday(&now, NULL);
    long diff = (((now.tv_sec - timer.tv_sec) * 1000000) + now.tv_usec - timer.tv_usec)/1000;
    return (int) diff;
}

// Check if the specified time delay has passed
int timerTimeOver()
{
    int ret = 0;

    if (getTimeDiff() > delay)
    {
        ret = 1;
        gettimeofday(&timer, NULL);
    }

    return ret;
}

// Print the time difference since initialization
void timerPrint()
{
    printf("Timer:  %d", getTimeDiff());
}