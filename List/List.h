//
// Created by kmord on 20.03.2022.
//

#ifndef UNTITLED2_LIST_H
#define UNTITLED2_LIST_H


#include <string>
#include "ListElement.h"

    class List {
    public:


        ListElement* HEAD = {nullptr};
        ListElement* TAIL = {nullptr};
        int size  = {0};

        void addEnd(int input);
        void addStart(int value);
        void add( int index,int value);
        void removeEnd();
        void removeStart();
        ListElement* get(int index);
        int search(int value);

        void remove(int index);
        std::string toString();
        void showInterface();
        void generateRandomData(int dataCount);
        void clearList();
        void test();

        double searchTest(int dataCount);
        double removeTest(int dataCount);
        double addTest(int dataCount);
        double addEndTest(int dataCount);
        double addStartTest(int dataCount);
        void readDataFromFile(std::string fileName);
    };



#endif //UNTITLED2_LIST_H
