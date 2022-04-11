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
        ListElement* search(int index);
        void remove(int index);
        std::string toString();
        void showInterface();
    };



#endif //UNTITLED2_LIST_H
