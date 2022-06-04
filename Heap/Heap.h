//
// Created by kmord on 10.04.2022.
//

#include <string>

#ifndef UNTITLED2_HEAP_H
#define UNTITLED2_HEAP_H

#endif //UNTITLED2_HEAP_H


class Heap{
public:

    void add(int value);
    int search(int value);
    int get(int index);
    bool removeRoot();
    std::string toString();
    bool swap(int parentIndex, int largestIndex);
    void heapMax(int pos);
    void showInterface();


private:
    int* heap = {nullptr};
    int size = 0 ;
    int parent(int pos);
    int leftChild (int pos);
    int rightChild(int pos);
    void test();
    void generateRandomData(int count);
    void repairHeap();
    void buildHeap();
    double addTest(int dataCount);
    double removeTest(int dataCount);
    double searchTest(int dataCount);
    void readDataFromFile(std::string fileName);


};