//
// Created by kmord on 20.03.2022.
//

#include <iostream>
#include <fstream>
#include "List.h"
#include "../Timer/Timer.h"


void List::addEnd(int value) {
    if (this->size == 0) {                                                          //jeżeli nowy element będzie pierwszym elementem w liście
        this->TAIL = new ListElement(value, {nullptr}, {nullptr});      //dodajemy nowy element jako ogon oraz głowa listy
        this->HEAD = this->TAIL;
    } else {
        this->TAIL->next = new ListElement(value,this->TAIL,{nullptr}); //następnikiem poprzedniego ogona staje się nowy element
        this->TAIL = this->TAIL->next;                                               //nowy element staje się nowym ogonem
    }
    this->size++;
}


    void List::addStart(int value){
    if(this->size == 0 ){
        this->HEAD = new ListElement(value,{nullptr},{nullptr});    //jeżeli nowy element będzie pierwszym elementem w liście
        this->TAIL = this->HEAD;                                                 //dodajemy nowy element jako ogon oraz głowa listy
    }else{
        this-> HEAD-> previous = new ListElement(value,{nullptr},this->HEAD); //poprzednikiem głowy staje się nowy element
        this->HEAD = this->HEAD->previous;                                                 //nowy element staje się nową głową
    }
    this->size ++;
}


ListElement* List::get(int index){
    ListElement* tempEl;
    if(index < this->size/2){               //jeżeli indeks znajduje się bliżej początku, interujemy od głowy, jeżeli bliżej końca, iterujemy od ogona
         tempEl =this->HEAD;
         for(int i = 0 ; i < index;i++){    // pobieramy następny element aż dotrzemy do poszukiwanego indeksu
             tempEl = tempEl->next;
         }
         return tempEl;
    }else{
        tempEl = this->TAIL;
        for(int i=size-1; i > index; i--){  // pobieramy poprzedni element aż dotrzemy do poszukiwanego indeksu
            tempEl = tempEl->previous;
        }
        return tempEl;
    }
}

int List::search(int value){
    ListElement* tempElement = this->HEAD;
    int index = 0;
    do{
        if(tempElement->value == value){
            return  index;
        }
        index++;
        tempElement = tempElement->next;
    }while(tempElement!=nullptr);
    return -1;
}

void List::remove(int index){
    ListElement* elementToRemove = get(index);

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
    ListElement* tempElement = get(index);                           // szukamy elementu za którym chcemy dodać nowy element
    ListElement* newElement= new ListElement(value,tempElement,tempElement->next); //tworzymy nowy element
    tempElement->next->previous=newElement;                             //element za nowym wskazuje na nowy
    tempElement->next = newElement;                                     //element przed nowym wskazuje na nowy

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

void List::generateRandomData(int dataCount){
    clearList();
    srand(time(NULL));
    for(int i = 0; i<dataCount;i++){
        addEnd(((std::rand()%1000)+1));
    }
};

void List::test(){                      //testy
    srand(time(NULL));
    Timer timer;
    double timeSum;
    double timeAvg;
    int numberOfTests=100;
    int dataCount =0;
    int randomIndex=0;

    timeAvg = 0;
    timeSum = 0;
    dataCount=100;

    addEndTest(100);
    addEndTest(1000);
    addEndTest(10000);
    addEndTest(100000);
    addEndTest(1000000);

    addStartTest(100);
    addStartTest(1000);
    addStartTest(10000);
    addStartTest(100000);
    addStartTest(1000000);

    addTest(100);
    addTest(1000);
    addTest(10000);
    addTest(100000);
    addTest(1000000);

    removeTest(100);
    removeTest(1000);
    removeTest(10000);
    removeTest(100000);
    removeTest(1000000);



    searchTest(100);
    searchTest(1000);
    searchTest(10000);
    searchTest(100000);
    searchTest(1000000);

}

double List::searchTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    int randomValue;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        randomValue= ((std::rand()%1000));
        generateRandomData(dataCount);
        timer.startTimer();
        search(randomValue);
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"search test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;
    return timeAvg;
}

double List::removeTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    int randomIndex;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        randomIndex= ((std::rand()%dataCount));
        generateRandomData(dataCount);
        timer.startTimer();
        remove(randomIndex);
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"remove test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;
    return timeAvg;
}

double List::addTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    int randomIndex;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        randomIndex= ((std::rand()%dataCount));
        generateRandomData(dataCount);
        timer.startTimer();
        add(randomIndex,10);
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"add test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;
    return timeAvg;
}

double List::addEndTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        generateRandomData(dataCount);
        timer.startTimer();
        addEnd(10);
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"add End test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;
    return timeAvg;
}

void  List::removeEnd(){
    ListElement* elementToRemove = this->TAIL;
    if(elementToRemove != nullptr) {
        this->TAIL = this->TAIL->previous;
        this->TAIL->next = {nullptr};
        delete elementToRemove;
        this->size--;
    }
}

void  List::removeStart(){

    ListElement* elementToRemove = this->HEAD;
    if(elementToRemove!= nullptr){
    this->HEAD= this->HEAD->next;
    this->HEAD->previous={nullptr};
    delete elementToRemove;
    this->size--;
    }

}

double List::addStartTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        generateRandomData(dataCount);
        timer.startTimer();
        addStart(10);
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"add Start test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;
    return timeAvg;
}
void List::clearList() {   //czyszczenie listy
    ListElement* tempEl;
    tempEl =this->HEAD;
    for(int i = 0 ; i < this->size;i++){
        delete tempEl->previous;
        tempEl = tempEl->next;
    }
    delete tempEl;
    this->size = 0;
    this->HEAD = nullptr;
    this->TAIL = nullptr;
}


void List::readDataFromFile(std::string fileName) {
    std::ifstream file(fileName); //otwieramy plik ze ścieżki podanej przez usera
    int elementsCount=0;
    std::string buff = "";
    std::getline(file,buff);
    elementsCount = std::stoi(buff); //pierwsza linia pliku zawiera ilość elementów w pliku

    clearList();

    for(int i =0 ; i<elementsCount ; i++){     // uzupełniamy pomocniczą tablicę wartościami z pliku
        std::getline(file,buff);
        addEnd(std::stoi(buff));
    }
    this -> size = elementsCount;              //ustalamy wielkosć nowej listy
}



void List::showInterface(){
    int userInput;
    int output;

    do{
        std::cout<<"1-search"<<std::endl;
        std::cout<<"2-add start"<<std::endl;
        std::cout<<"3-add end"<<std::endl;
        std::cout<<"4-add"<<std::endl;
        std::cout<<"5-remove start"<<std::endl;
        std::cout<<"6-remove end"<<std::endl;
        std::cout<<"7-remove"<<std::endl;
        std::cout<<"8-test"<<std::endl;
        std::cout<<"9-show list"<<std::endl;
        std::cout<<"10-read data from file"<<std::endl;
        std::cout<<"11-exit"<<std::endl;
        std::cin>>userInput;
        switch(userInput){
            case 1:{
                std::cout<<"wartosc do wyszukania:\n";
                std::cin>>userInput;
                std::cout<<"znaleziono na indeksie: "<<search(userInput)<<std::endl;
                break;
            }
            case 2:{
                std::cout<<"podaj wartosc do dodania\n";
                std::cin>>userInput;
                addStart(userInput);
                break;
            }
            case 3:{
                std::cout<<"podaj wartosc do dodania\n";
                std::cin>>userInput;
                addEnd(userInput);
                break;
            }
            case 4:{
                int index;
                std::cout<<"podaj wartosc do dodania\n";
                std::cin>>userInput;
                std::cout<<"podaj gdzie ma sie znalezc wartosc\n";
                std::cin>>index;
                add(index,userInput);
                break;
            }
            case 5:{
                removeStart();
                break;
            }
            case 6:{
                removeEnd();
                break;
            }
            case 7:{
                std::cout<<"podaj indeks elementu do usuniecia\n";
                std::cin>>userInput;
                remove(userInput);
                break;
            }
            case 8:{
                test();
                break;
            }
            case 9:{
                std::cout<<std::endl<<toString()<<std::endl;
                break;
            }
            case 10:{

                std::string filePath;
                std::cout<<"file path:"<<std::endl;
                std::cin>>filePath;
                readDataFromFile(filePath);
                break;
            }
            default:{
                userInput=11;
            }

        }
    }while(userInput!=11);
}


