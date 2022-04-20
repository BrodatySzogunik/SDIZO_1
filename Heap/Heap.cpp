//
// Created by kmord on 11.04.2022.
//

#include "Heap.h"
#include "../Timer/Timer.h"
#include <bits/stdc++.h>



void Heap::add(int value){
    int* newHeap = new int[this->size+1];       //tworzymy nową tablicę o rozmiarze większym od poprzedniej
    newHeap[this->size] = value;                //dodajemy warość na koniec nowej tablicy

    if(this->heap!= nullptr){                   //kopjujemy wartości poprzedniej tablicy do nowej
        for(int i = 0 ; i < this->size ; i++){
            newHeap[i] = this->heap[i];
        }
        delete [] this->heap;                   //usuwamy starą tablicę
    }

    this->size++;                               //zwiększamy rozmiar
    this->heap  = newHeap;                      //podmieniamy wskaźnik starej tablicy na nowy
    repairHeap();                               // przywracamy wartosć kopca
}

void Heap::repairHeap(){
    int current = this->size-1;
    while(this->heap[current]>this->heap[parent(current)]){ //największa wartość wypływa na górę
        swap(parent(current),current);
        current = parent(current);
    }
}

bool Heap::removeRoot(){
    int root = this->heap[0];
    this->heap[0] = this->heap[--this->size];   //zamieniamy ostatni element kopca z korzeniem
    delete &this->heap[this->size+1];           // usuwamy ostatni element kopca
    heapMax(0);                            // kopcujemy od korzenia
    return root;
}

int Heap::search(int value){
    for(int i = 0 ; i < this->size ; i++){      //iteracja przez kopiec w celu znalezienia porządanej wartości
        if(this->heap[i] == value){
            return i;
        }
    }
    return -1;
}

int Heap::get(int index){
    return this->heap[index];
}



std::string Heap::toString(){
   int heapHeight = floor(log2(this->size));
   int heapWidth = pow(2,heapHeight)*2;
   int actualHeight = 0;
   int bigSpaceSize=0;
   int smallSpaceSize=0;
   int bigSpaceCounter=0;
   int heapIterator=0;


   std::string output="";

   for(;actualHeight<=heapHeight; actualHeight++){
       bigSpaceCounter=pow(2,actualHeight)-1;
       bigSpaceSize = smallSpaceSize;
       smallSpaceSize = pow(2,heapHeight - actualHeight)-1;


        for(int i = 0; i<smallSpaceSize;i++) {
            output += ".";
        }
        do{
            if(heapIterator+1<=this->size){
                output+= std::to_string(this->heap[heapIterator++]);
            }else{
                output+=".";
            }
            if(bigSpaceCounter>0){
                for(int i = 0 ; i < bigSpaceSize; i++){
                    output+=".";
                }
            }
        }while(bigSpaceCounter-->0);
       for(int i = 0; i<smallSpaceSize;i++) {
           output += ".";
       }
       output+='\n';
   }
   return output;


}

int Heap::leftChild(int pos){
    if(pos ==0){
        return  1;
    }else{
        return pos * 2;
    }
}

int Heap::rightChild(int pos) {
    if(pos == 0 ){
        return 2;
    }else{
    return pos*2+1;}
}

int Heap::parent(int pos){
    return floor(pos/2);
}

bool Heap::isLeaf(int pos) {
    if(pos>(size/2) && pos<= size){
        return true;
    }else{
        return false;
    }
};

void Heap::swap(int firstPos, int secondPos){
    int temp;
    temp = this->heap[secondPos];
    this->heap[secondPos]= this->heap[firstPos];
    this->heap[firstPos] = temp;
}

void Heap::heapMax(int pos){
    if (isLeaf(pos))
        return;
    int largest = pos ;

    if(this->heap[largest]<this->heap[leftChild(pos)] && leftChild(pos)<this->size){
        largest= leftChild(pos);
    }
    if(this->heap[largest]<this->heap[rightChild(pos)] && rightChild(pos)<this->size ){
        largest = rightChild(pos);
    }

    if(this->heap[pos]!=this->heap[largest]){
        swap(largest,pos);
        heapMax(largest);
        heapMax(pos);}

}
void Heap::buildHeap(){
    for(int i = floor((this->size-1)/2); i>=0; i--){
        heapMax(i);
    }
}

void Heap::generateRandomData(int count) {
    srand( time( NULL ) );
    int* randomTab = new int[count];
    for(int i=0 ; i<count; i++){
        randomTab[i] = ((std::rand()%1000)+1);
    }
    delete[] this->heap;
    this->size = count;
    this->heap = randomTab;
buildHeap();

}

void Heap::test(){
    srand(time(NULL));


    addTest(10);
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
double Heap::addTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        generateRandomData(dataCount);
        timer.startTimer();
        add(10);
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"add test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;
    return timeAvg;
};
double Heap::removeTest(int dataCount){
    int timeAvg = 0;
    int timeSum = 0;
    int numberOfTests = 100;
    Timer timer;
    for(int i=0;i<numberOfTests;i++){
        generateRandomData(dataCount);
        timer.startTimer();
        removeRoot();
        timeSum += timer.getTimer();
    }
    timeAvg = timeSum/numberOfTests;
    std::cout<<"remove test for "<<dataCount<<" elements :"<<timeAvg<<std::endl;
    return timeAvg;
};
double Heap::searchTest(int dataCount){
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
};


void Heap::readDataFromFile(std::string fileName) {
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

    this->heap = newTable;//przypisujemy adres pierwszej komurki tabeli pomocniczej w miejsce tablicy głównej
    this -> size = elementsCount;              //ustalamy wielkosć nowej tablicy
    buildHeap();
}



void Heap::showInterface() {
    int userInput;
    int output;

    do{
        std::cout<<"1-search"<<std::endl;
        std::cout<<"2-add"<<std::endl;
        std::cout<<"5-remove"<<std::endl;
        std::cout<<"6-test"<<std::endl;
        std::cout<<"7-show heap"<<std::endl;
        std::cout<<"8-read from file"<<std::endl;
        std::cout<<"9-exit"<<std::endl;
        std::cin>>userInput;
        switch(userInput){
            case 1:{
                std::cout<<"wartosc do wyszukania:\n";
                std::cin>>userInput;
                std::cout<<search(userInput)<<std::endl;
                break;
            }
            case 2:{
                std::cout<<"podaj wartosc do dodania\n";
                std::cin>>userInput;
                add(userInput);
                break;
            }
            case 5:{
                removeRoot();
                break;
            }
            case 6:{
                test();
                break;
            }
            case 7:{
                std::cout<<toString()<<std::endl;
                break;
            }
            case 8:{
                std::string filePath;
                std::cout<<"file path:"<<std::endl;
                std::cin>>filePath;
                readDataFromFile(filePath);
                break;
            }
            default:{
                userInput=9;
            }

        }
    }while(userInput!=9);
}



