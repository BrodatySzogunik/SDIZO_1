#include <iostream>
#include <string>
#include <cstdlib>
#include "DynamicArray/DynamicArray.h"
#include "List/List.h"
#include "Heap/Heap.h"
#include "Timer/Timer.h"

int main() {

DA::DynamicArray array(0);
List list;
Heap heap;
Timer timer;


int userInput;

    do{
        userInput=0;
        std::cout<<"1-tablica dynamiczna"<<std::endl;
        std::cout<<"2-lista dwukierunkowa"<<std::endl;
        std::cout<<"3-kopiec binarny"<<std::endl;
        std::cout<<"4-wyjscie"<<std::endl;
        std::cin>>userInput;
        switch(userInput) {
            case 1: {
                array.showInterface();
                break;
            }
            case 2:{
                list.showInterface();
                break;
            }
            case 3:{
                heap.showInterface();
                break;
            }
            default:{
                userInput = 4;
            }
        }
    }while(userInput!=4);
    return  0 ;






}