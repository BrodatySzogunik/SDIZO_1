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
    int actualChild = this->size-1;                   //rozpoczynamy od ostatnio dodanego węzła
    int actualParent = parent(actualChild);
    bool swapped = true;
    while(actualChild != 0 && swapped  ){             //dopóki jest potrzeba zamiany
        swapped = swap(actualParent,actualChild);
        actualChild = actualParent;
        actualParent = parent(actualParent);
    }
}

bool Heap::removeRoot(){
    if(this->size>0){

        this->size--;                          //zmniejszamy rozmiar
        int* tempTab = new int[this->size];    //tworzymy tabelę o zmniejszonym rozmiarze
        tempTab[0] = this->heap[this->size];

        for (int i = 1; i < this->size; i++) { //kopiujemy elementy  pierwszy element
            tempTab[i] = this->heap[i];
        }
        delete[] this->heap;                 //usuwamy starą tabelę
        this->heap = tempTab;                   //przypisujemy wskaźnik nowej tabeli w miejsce starej
    }
    this->heapMax(0);
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

bool Heap::swap(int firstPos, int secondPos){

    if (this->size != 0){                                   //sprawdzamy czy heap nie jest pusty
        if (this->heap[secondPos] > this->heap[firstPos])   //jeżeli  pierwszy el jest większy od drugiego- następuje zamiana
        {
            int value = this->heap[firstPos];
            this->heap[firstPos] = this->heap[secondPos];
            this->heap[secondPos] = value;
            return true;
        }
    }
    return false;
}

void Heap::heapMax(int pos){
    int left  = leftChild(pos);
    int right = rightChild(pos);
    int largest = pos;

    if (left < this->size && this->heap[left] > this->heap[largest])
    {
        largest = left;
    }

    if (right < this->size && this->heap[right] > this->heap[largest])
    {
        largest = right;
    }

    if (this->swap(pos, largest))
    {
        this->heapMax(largest);
    }

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
        randomTab[i] = ((std::rand()%INT_MAX)+1);
    }
    delete[] this->heap;
    this->size = count;
    this->heap = randomTab;
buildHeap();

}

void Heap::test(){
    srand(time(NULL));
    std::fstream file("Heap.txt",std::fstream::out | std::fstream::app);

    file<<"count;addTest;removeTest;searchTest"<<std::endl;
    for(int i = 1; i<16 ; i++){
        file<<i*1000<<";"
            <<addTest(i*1000)<<";"
            <<removeTest(i*1000)<<";"
            <<searchTest(i*1000)
            <<std::endl;
    }

    file.close();
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
                std::cout<<"znaleziono na indexie :"<<search(userInput)<<std::endl;
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



