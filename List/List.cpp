//
// Created by kmord on 20.03.2022.
//

#include <iostream>
#include "List.h"



void List::addEnd(int value) {
    if (this->size == 0) {
        this->TAIL = new ListElement(value, {nullptr}, {nullptr});
        this->HEAD = this->TAIL;
    } else {
        this->TAIL->next = new ListElement(value,this->TAIL,{nullptr});
        this->TAIL = this->TAIL->next;
    }
    this->size++;
}


    void List::addStart(int value){
    if(this->size == 0 ){

        this->HEAD = new ListElement(value,{nullptr},{nullptr});
        this->TAIL = this->HEAD;
    }else{
        this-> HEAD-> previous = new ListElement(value,{nullptr},this->HEAD);
        this->HEAD = this->HEAD->previous;
    }
    this->size ++;
}


ListElement* List::search(int index){
    ListElement* tempEl;
    if(index < this->size/2){
         tempEl =this->HEAD;
         for(int i = 0 ; i < index;i++){
             tempEl = tempEl->next;
         }
         return tempEl;
    }else{
        tempEl = this->TAIL;
        for(int i=size-1; i > index; i--){
            tempEl = tempEl->previous;
        }
        return tempEl;
    }
}

void List::remove(int index){
    ListElement* elementToRemove = search(index);

    if(this->HEAD == elementToRemove){
        this->HEAD= elementToRemove->next;
        this->HEAD->previous={nullptr};
    }else if(this->TAIL == elementToRemove){
        this->TAIL = elementToRemove->previous;
        this->TAIL->next = {nullptr};
    }else {
        elementToRemove->next->previous = elementToRemove->previous;
        elementToRemove->previous->next = elementToRemove->next;
        delete elementToRemove;

    }
    this->size--;
}

void List::add(int value,int index){
    ListElement* tempElement = search(index);
    ListElement* newElement= new ListElement(value,tempElement,tempElement->next);
    tempElement->next->previous=newElement;
    tempElement->next = newElement;

    this->size++;
}

std::string List::toString(){
    std::string output="";
    ListElement* temp = HEAD;
    do{

            output +=std::to_string(temp->value);
            output +=" ; ";
            temp = temp->getNext();

    }while(temp!= nullptr);
    return output;
}
void List::showInterface(){
    int userInput;
    int output;

    do{
        std::cout<<"1-search"<<std::endl;
        std::cout<<"2-add start"<<std::endl;
        std::cout<<"3-add end"<<std::endl;
        std::cout<<"4-add"<<std::endl;
        std::cout<<"5-remove"<<std::endl;
        std::cout<<"6-show array"<<std::endl;
        std::cout<<"7-wyjscie"<<std::endl;
        std::cin>>userInput;
        switch(userInput){
            case 1:{
                std::cout<<"wartość do wyszukania:\n";
                std::cin>>userInput;
                std::cout<<search(userInput)->value<<std::endl;
                break;
            }
            case 2:{
                std::cout<<"podaj wartość do dodania\n";
                std::cin>>userInput;
                addStart(userInput);
                break;
            }
            case 3:{
                std::cout<<"podaj wartość do dodania\n";
                std::cin>>userInput;
                addEnd(userInput);
                break;
            }
            case 4:{
                int index;
                std::cout<<"podaj wartość do dodania\n";
                std::cin>>userInput;
                std::cout<<"podaj gdzie ma sie znalezc wartosc\n";
                std::cin>>index;
                add(index,userInput);
                break;
            }
            case 5:{
                std::cout<<"podaj indeks elementu do usunięcia\n";
                std::cin>>userInput;
                remove(userInput);
                break;
            }
            case 6:{
                std::cout<<toString()<<std::endl;
                break;
            }
            default:{
                userInput=7;
            }

        }
    }while(userInput!=7);
}


