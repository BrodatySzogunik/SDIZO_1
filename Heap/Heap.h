//
// Created by kmord on 10.04.2022.
//

#include <string>
#include "HeapElement.h"

#ifndef UNTITLED2_HEAP_H
#define UNTITLED2_HEAP_H

#endif //UNTITLED2_HEAP_H


class Heap{
public:

    void add(int value);
    int search(int value);
    bool removeRoot();
    std::string toString();
    void swapWhenNeeded(int parentIndex, int largestIndex);
    void heapMax();


private:
    int* heap = {nullptr};
    int size = 0 ;

    void repairHeap();


};