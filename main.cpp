#include <iostream>
#include <string>
#include <algorithm>
#include "DynamicArray/DynamicArray.h"
#include "List/List.h"
#include "List/ListElement.h"
#include "Heap/Heap.h"

int main() {


//DA::DynamicArray array(0);
//List list;
//Heap heap;
//
//heap.add(1);
//heap.add(2);
//heap.add(3);
//heap.add(4);
//heap.add(5);
//heap.add(6);
//heap.add(7);
//heap.add(8);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//heap.add(9);
//
//
//
//std::cout<<heap.toString();

DA::DynamicArray array(0);
List list;




int userInput;

    do{
        userInput=0;
        std::cout<<"1-tablica dynamiczna"<<std::endl;
        std::cout<<"2-lista dwukierunkowa"<<std::endl;
        std::cout<<"3-kopiec binarny"<<std::endl;
        std::cout<<"4-wyjscie"<<std::endl;
        std::cin>>userInput;
        switch(userInput) {
            case 1:{
                array.showInterface();
            }
                break;
            case 2:{
                list.showInterface();
            }
                break;
        }
    }while(userInput!=4);
    return  0 ;






}