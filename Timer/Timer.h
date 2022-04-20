//
// Created by Kuba on 16.04.2022.
//

#include <cwchar>

#ifndef SDIZO_1_TIMER_H
#define SDIZO_1_TIMER_H

#endif //SDIZO_1_TIMER_H
class Timer{

    double PCFreq ;
    __int64 CounterStart ;
public:
    void startTimer();
    double getTimer();
    void Test();

};