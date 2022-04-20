//
// Created by Kuba on 16.04.2022.
//
#include <ntdef.h>
#include <profileapi.h>
#include <iostream>
#include"Timer.h"

using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void Timer::startTimer()
{
    CounterStart = 0.0;
    PCFreq = 0;

    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double Timer::getTimer()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}