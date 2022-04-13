//
// Created by kmord on 11.04.2022.
//

#include "Heap.h"
#include <bits/stdc++.h>



void Heap::add(int value){
    int* newHeap = new int[this->size+1];
    newHeap[this->size] = value;

    if(this->heap!= nullptr){
        for(int i = 0 ; i < this->size ; i++){
            newHeap[i] = this->heap[i];
        }
        delete [] this->heap;
    }

    this->size++;
    this->heap  = newHeap;
    this->repairHeap();
}


bool Heap::removeRoot(){
    if(this->size == 0){
        return false;
    }

    int* newHeap = new int[this->size-1];
    for(int i=0 ; i<this->size-1 ;i++){
        newHeap[i] = this->heap[i+1];
    }
    delete [] this->heap;

    this->heap = newHeap;
    this->size++;
    this->repairHeap();
    return false;
}

int Heap::search(int value){
    for(int i = 0 ; i < this->size ; i++){
        if(this->heap[i] == value){
            return i;
        }
    }
    return -1;
}

void Heap::repairHeap(){}


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

void Heap::heapMax(){

}



