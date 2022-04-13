//
// Created by kmord on 17.03.2022.
//

#include <iostream>
#include <fstream>
#include "DynamicArray.h"

using namespace DA;



 DynamicArray::DynamicArray(int size){
     this -> size = size;
     this -> table = new int[size];
}

DynamicArray::DynamicArray(std::string fileName){
    std::fstream file;
    file.open(fileName,std::ios::out);
    int elementsCount=0;
    std::string buff;
    file>>buff;
    std::stoi(buff)>>elementsCount;

    int* newTable= new int[elementsCount];



    for(int i=0 ; i<elementsCount ; i++){
        file>>buff;
        newTable[i]= std::stoi(buff);
    }

    this->table = newTable;
    this -> size = elementsCount;
}

DynamicArray::~DynamicArray(){
     for(int i = 0 ; i<this->size; i++){
         this->table[i] = 0 ;

     }
     delete[] this -> table;
 }

 void DynamicArray::addEnd(int input){
     int* tempTab = new int[this->size+1] ;
     for(int i = 0 ; i< this->size; i++){
         tempTab[i] = this ->table[i];
         this->table[i] =0;
     }
     delete[] table;
     this->size++;
     tempTab[this->size-1] = input;
     this->table = tempTab;

 }

 void DynamicArray::addStart(int input){
     this->size++;
     int* tempTab = new int[this->size];
     tempTab[0] = input;
     for(int i = 0 ; i< this->size; i++){
         tempTab[i+1] = this ->table[i];
     }
     delete[] table;
     this -> table = tempTab;
 }

 void DynamicArray::add(int index,int input){
     this->size++;
     int* tempTab = new int[this->size];
     bool isMiddleInserted = false;
     for(int i = 0 ; i<this->size; i++){
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

 void DynamicArray::removeValue(int index) {
     this->size--;
     int* tempTab = new int[this->size];
     int mainTableIterator = 0;
     for(int tempTableIterator=0;tempTableIterator<this->size;mainTableIterator++ ){
         if(mainTableIterator != index){
             tempTab[tempTableIterator++] = this->table[mainTableIterator];
         }
     }
     delete[] table;
     this ->table = tempTab;
 }

    int DynamicArray::get(int index){
        return table[index];
    }

    void DynamicArray::setValue(int index, int value){
     if(inRange(index)){
         this->table[index] = value;
     }
}

    int DynamicArray::search(int value) {
    for(int i = 0 ; i<this->size;i++){
        if(this->table[i] == value){
            return i;
        }

    }
        return -1;
 }

 std::string DynamicArray::toString(){
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

  void DynamicArray::showInterface(){
     int userInput;
     int output;

     do{
         std::cout<<"1-search"<<std::endl;
         std::cout<<"2-add start"<<std::endl;
         std::cout<<"3-add end"<<std::endl;
         std::cout<<"4-add"<<std::endl;
         std::cout<<"5-remove"<<std::endl;
         std::cout<<"6-randomize"<<std::endl;
         std::cout<<"7-show array"<<std::endl;
         std::cout<<"8-wyjscie"<<std::endl;
         std::cin>>userInput;
         switch(userInput){
             case 1:{
                 std::cout<<"wartość do wyszukania:\n";
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
                 removeValue(userInput);
                 break;
                 }
             case 6:{
                 std::cout<<"podaj ilość danych do wylosowania\n";
                 std::cin>>userInput;
                 generateRandomData(userInput);
                 break;
             }
             case 7:{
                 std::cout<<toString()<<std::endl;
                 break;
             }
             default:{
                 userInput=8;
             }

         }
     }while(userInput!=8);
 }

void DynamicArray::generateRandomData(int count){
    srand( time( NULL ) );
     int* randomTab = new int[count];
     for(int i=0 ; i<count; i++){
         randomTab[i] = ((std::rand()%100)+1);
     }
     delete[] this->table;
     this->size = count;
     this->table = randomTab;
 }