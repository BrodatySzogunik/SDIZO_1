//
// Created by kmord on 17.03.2022.
//
#include <string>
#ifndef UNTITLED2_DYNAMICARRAY_H
#define UNTITLED2_DYNAMICARRAY_H

namespace DA{

    class DynamicArray {
    public :
        DynamicArray(int size);
        DynamicArray(std::string fileName);
        ~DynamicArray();


        int* table;
        int size ;


        void addEnd(int input);
        void add(int index, int input);
        void addStart(int input);
        void removeValue(int index);
        void setValue(int index,int value);
        int get(int index);
        int search(int value);
        void showInterface();
        std::string toString();
        void generateRandomData(int count);

    private:
        bool inRange(int index);



    };

}

#endif //UNTITLED2_DYNAMICARRAY_H
