//
// Created by kmord on 17.03.2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include "DynamicArray.h"
#include "../Timer/Timer.h"

using namespace DA;



 DynamicArray::DynamicArray(int size){
     this -> size = size;
     this -> table = new int[size];
}

DynamicArray::~DynamicArray(){
     for(int i = 0 ; i<this->size; i++){
         this->table[i] = 0 ;

     }
     delete[] this -> table;
 }

 void DynamicArray::readDataFromFile(std::string fileName) {
     std::ifstream file(fileName); //otwieramy plik ze ścieżki podanej przez usera
     int elementsCount=0;
     std::string buff = "";
     std::getline(file,buff);
     elementsCount = std::stoi(buff); //pierwsza linia pliku zawiera ilość elementów w pliku

     int* newTable= new int[elementsCount]; //tworzymy pomocniczą dynamiczną tablicę

     for(int i =0 ; i<elementsCount ; i++){     // uzupełniamy pomocniczą tablicę wartościami z pliku
         std::getline(file,buff);
         newTable[i] = std::stoi(buff);
     }

     this->table = newTable;                    //przypisujemy adres pierwszej komurki tabeli pomocniczej w miejsce tablicy głównej
     this -> size = elementsCount;              //ustalamy wielkosć nowej tablicy
 }

 void DynamicArray::addEnd(int input){          //dodawanie na końcu tablicy
     int* tempTab = new int[this->size+1] ;     //tworzymy tablicę pomocniczą do kopiowania danych
     for(int i = 0 ; i< this->size; i++){       //kopjujemy dane ze starej tablicy do nowej
         tempTab[i] = this ->table[i];
         this->table[i] =0;
     }
     delete[] table;                            //usuwamy wcześniej wyzerowaną starą tablicę
     this->size++;                              //inkrementujemy rozmiar tablicy zapisany w objekcie
     tempTab[this->size-1] = input;             //przypisujemy nowy element na koniec nowej tablicy
     this->table = tempTab;                     //podmieniamy wskaźnik starej tablicy na nowy

 }

 void DynamicArray::addStart(int input){
     this->size++;
     int* tempTab = new int[this->size];
     tempTab[0] = input;                         //dodajemy nowy element na początek nowej tablicy
     for(int i = 0 ; i< this->size; i++){        //kopjujemy wartości ze starej tablicy oraz ją zerujemy
         tempTab[i+1] = this ->table[i];
         this ->table[i] = 0;
     }
     delete[] table;                             //usuwamy starą tablicę
     this -> table = tempTab;                    //podmieniamy wskaźnik starej tablicy na nowy
 }

 void DynamicArray::add(int index,int input){
     this->size++;
     int* tempTab = new int[this->size];
     bool isMiddleInserted = false;
     for(int i = 0 ; i<this->size; i++){        //dodajemy nowy element na indeks podany przez usera
         if(i==index){
             tempTab[i]= input;
             isMiddleInserted = true;
         }else{
             tempTab[i]=isMiddleInserted?this->table[i-1]:this->table[i];
         }
     }
     delete[] table;
     this->table = tempTab;
 }

 void DynamicArray::remove(int index) {        //usuwamy wartość z podanego przez usera indexu
     this->size--;
     int* tempTab = new int[this->size];            //tworzymy pomocniczą tablicę
     int mainTableIterator = 0;
     for(int tempTableIterator=0;tempTableIterator<this->size;mainTableIterator++ ){    // do nowej tablicy kopjujemy wartości poza elementem który chcemy usunąć
         if(mainTableIterator != index){
             tempTab[tempTableIterator++] = this->table[mainTableIterator];
         }
     }
     delete[] table;                                                                    //usuwamy starą tablicę
     this ->table = tempTab;                                                            //podmieniamy wskaźnik na starą tablicę na nowy
 }

 void DynamicArray::removeEnd(){
     if(this->size>0){
         this->size--;                          //zmniejszamy rozmiar
         int *tempTab = new int[this->size];    //tworzymy tabelę o zmniejszonym rozmiarze
         for (int i = 0; i < this->size; i++) { //kopiujemy elementy pomijając ostatni element
             tempTab[i] = this->table[i];
         }
         delete[] this->table;                 //usuwamy starą tabelę
         this->table = tempTab;
     }                //przypisujemy wskaźnik nowej tabeli w miejsce starej
 };

 void DynamicArray::removeStart(){
     if(this->size>0){
         this->size--;                            //zmniejszamy rozmiar
         int *tempTab = new int[this->size];      //tworzymy tabelę o zmniejszonym rozmiarze
         for (int i = 0; i < this->size; i++) {   //kopiujemy elementy pomijając pierwszy element
             tempTab[i] = this->table[i + 1];       //usuwamy starą tabelę
         }
         delete[] this->table;                   //przypisujemy wskaźnik nowej tabeli w miejsce starej
         this->table = tempTab;
     }
 };

    int DynamicArray::get(int index){
        return table[index];        //zwracamy wartosć znajdującą się pod indeksem podanym przez usera
    }

    void DynamicArray::setValue(int index, int value){
     if(inRange(index)){
         this->table[index] = value;        // ustawiamy wartość z indexu podanego przez usera na wartość podaną przez usera
     }
}

    void DynamicArray::search(int value) {       // jeżeli znajdziemy element pasujący do wymagań - zwracamy jego wartość, jeżeli nie , zwracamy -1
    for(int i = 0 ; i<this->size;i++){
        if(this->table[i] == value){
            return true;
        }

    }
        return false;
 }

 std::string DynamicArray::toString(){      // wyświetlanie tablicy
     std::string output = "";
     for(int i = 0 ; i < this->size;i++){
         output+=std::to_string(this->table[i]);
         output+=" ; ";
     }
     return output;
 }



bool DynamicArray::inRange(int index) {
     return index>=0&&index<this->size;
 }

 void DynamicArray::test(){             //testowanie czasu działania poszczególnych operacji
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

     std::fstream file("Array.txt",std::fstream::out | std::fstream::app);

        file<<"count;addEndTest;addStartTest;addTest;removeStartTest;removeEndTest;removeTest;searchTest"<<std::endl;
     for(int i = 1; i<16 ; i++){
         file<<i*1000<<";"
         <<addEndTest(i*1000)<<";"
         <<addStartTest(i*1000)<<";"
         <<addTest(i*1000)<<";"
         <<removeStartTest(i*1000)<<";"
         <<removeEndTest(i*1000)<<";"
         <<removeTest(i*1000)<<";"
         <<searchTest(i*1000)
         <<std::endl;
     }

     file.close();

 }

 double DynamicArray::searchTest(int dataCount){
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

double DynamicArray::removeTest(int dataCount){
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
double DynamicArray::removeStartTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        generateRandomData(dataCount);
        timer.startTimer();
        removeStart();
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"remove test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;

    return timeAvg;
}

double DynamicArray::removeEndTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        generateRandomData(dataCount);
        timer.startTimer();
        removeEnd();
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"remove test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;

    return timeAvg;
}

double DynamicArray::addTest(int dataCount){
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

double DynamicArray::addEndTest(int dataCount){
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

double DynamicArray::addStartTest(int dataCount){
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


  void DynamicArray::showInterface(){
     int userInput;
     int output;

     do{
         userInput = 0 ;
         std::cout<<"1-search"<<std::endl;
         std::cout<<"2-add start"<<std::endl;
         std::cout<<"3-add end"<<std::endl;
         std::cout<<"4-add"<<std::endl;
         std::cout<<"5-remove start"<<std::endl;
         std::cout<<"6-remove end"<<std::endl;
         std::cout<<"7-remove"<<std::endl;
         std::cout<<"8-randomize"<<std::endl;
         std::cout<<"9-show array"<<std::endl;
         std::cout<<"10-test"<<std::endl;
         std::cout<<"11-get data from file"<<std::endl;
         std::cout<<"12-Exit"<<std::endl;
         std::cin>>userInput;
         switch(userInput){
             case 1:{
                 std::cout<<"wartosc do wyszukania:\n";
                 std::cin>>userInput;
                 output = search(userInput);
                 if(output!=-1){
                     std::cout<<"znaleziono na indeksie: "<<output<<std::endl;
                 }else{
                     std::cout<<"nie znaleziono elementu"<<std::endl;
                 }
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
                 std::cout<<"podaj ilosc danych do wylosowania\n";
                 std::cin>>userInput;
                 generateRandomData(userInput);
                 break;
             }
             case 9:{
                 std::cout<<std::endl<<toString()<<std::endl;
                 break;
             }
             case 10:{
                test();
                 break;
             }
             case 11:{
                 std::string filePath;
                 std::cout<<"file path:"<<std::endl;
                 std::cin>>filePath;
                 readDataFromFile(filePath);
                 break;
             }
             default:{
                 userInput=12;
             }

         }
     }while(userInput!=12);
 }

void DynamicArray::generateRandomData(int count){  //zapełnianie tablicy losowymi wartościami
    srand( time( NULL ) );
     int* randomTab = new int[count];
     for(int i=0 ; i<count; i++){
         randomTab[i] = ((std::rand()%INT_MAX)+1);
     }
     delete[] this->table;
     this->size = count;
     this->table = randomTab;
 }