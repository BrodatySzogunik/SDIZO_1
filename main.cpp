#include <iostream>
#include <string>
#include <algorithm>
#include "DynamicArray/DynamicArray.h"
#include "List/List.h"
#include "List/ListElement.h"

int main() {


DA::DynamicArray array(0);
List list;

//array.setValue(0,4);
//array.setValue(1,2);
//array.setValue(2,3);
//array.setValue(3,5);
//
//    std::cout<<std::endl;
//    std::cout<<array.toString();
//
//array.addEnd(4);
//
//    std::cout<<std::endl;
//    std::cout<<array.toString();
//
//array.addMiddle(8);
//
//    std::cout<<std::endl;
//    std::cout<<array.toString();
//
//    array.addStart(10);
//
//    std::cout<<std::endl;
//    std::cout<<array.toString();
//
//array.removeValue(0);
//    std::cout<<std::endl;
//    std::cout<<array.toString();
//
//    std::cout<<std::endl;
//std::cout<< array.search(4);
//
//std::cout<<std::endl;
//std::cout<<array.get(1);
//
//std::cout<<std::endl;
//
//List linkedList;
//
//linkedList.addStart(69);
//linkedList.addStart(65);
//linkedList.addStart(64);
//linkedList.addStart(63);
//linkedList.addEnd(90);
//linkedList.addEnd(90);
//linkedList.addEnd(90);
//
//std::cout<<std::endl;
//std::cout<<linkedList.search(1)->value;
//    std::cout<<std::endl;
//linkedList.remove(1);
//    std::cout<<std::endl;
//std::cout<<linkedList.search(1)->value;

//
//linkedList.add(50,2);
//std::cout<<std::endl;
//std::cout<<linkedList.search(0)->value<<std::endl;
//std::cout<<linkedList.search(1)->value<<std::endl;
//std::cout<<linkedList.search(2)->value<<std::endl;
//std::cout<<linkedList.search(3)->value<<std::endl;
//std::cout<<linkedList.search(4)->value<<std::endl;
//std::cout<<linkedList.search(5)->value<<std::endl;
//std::cout<<linkedList.search(6)->value<<std::endl;
//std::cout<<linkedList.search(7)->value<<std::endl;
//std::cout<<linkedList.search(8)->value<<std::endl;
//
//
//std::cout<<linkedList.HEAD->next->next->next->next->value << "cipa\n";

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