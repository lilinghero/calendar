#include "LineList.h"
#include <iostream>
using namespace std;

int LineList::listEmpty(int *firstAddress){
    if(*firstAddress){
        return 1;
    }else{
        return 0;
    }
}

int LineList::listLength(int *firstAddress){
    int length=0;
    if(this->listEmpty(firstAddress)){
        while(*firstAddress){
            length++;
            firstAddress++;
        }
        return length;
    }else{
        return 0;
        cout<<"this is a empty list."<<endl;
    }
}

int LineList::locateElem(int *firstAddress, int targetElem){
    for(int number=0;number < this->listLength(firstAddress);number++){
        if(*(firstAddress+number) == targetElem){
            return number;
        }else{
            cout<<"not found your targetElem."<<endl;
            return 0;
        }
    }
}

int LineList::priorElem(int *firstAddress, int number){
    if(number <= 0||number >= this->listLength(firstAddress)){
        cout<<"this is the frist element, or your number out of the length."<<endl;
        return 0;
    }else{
       return *(firstAddress+number-1);
    }
}

int LineList::nextElem(int *firstAddress, int number){
    if(number < 0 || number >= (this->listLength(firstAddress)-1)){;
        cout<<"this is the last element, or your number is < 0. "<<endl;
        return 0;
    }else{
        return *(firstAddress+number+1);
    }
}

int LineList::getElem(int *firstAddress, int number){
    if(number >= 0 && number <(this->listLength(firstAddress))){
        return *(firstAddress+number);
    }else{
        cout<<"your number out scope of the list."<<endl;
        return 0;
    }
}

void LineList::clearList(int *firstAddress){
    if(this->listEmpty(firstAddress) == 1){
        for(int i=0;i<this->listLength(firstAddress);i++){
            *(firstAddress+i)=0;
        }
    }
}

void LineList::putElem(int *firstAddress, int newElem){
    if(this->listEmpty(firstAddress) == 1){
        *(firstAddress+this->listLength(firstAddress))=newElem;
    }
}

void LineList::listDelete(int *firstAddress,int number){
    if(number >= 0 && number < this->listLength(firstAddress)){
        for( int i=number;i< this->listLength(firstAddress);i++){
           * (firstAddress+i)=*(firstAddress+i+1);
        }
        *(firstAddress+this->listLength(firstAddress)-1)=0;
    }
}

void LineList::listInsert(int *firstAddress, int number,int newElem){
    if(number >= 0 && number < this->listLength(firstAddress)){
        for(int i=this->listLength(firstAddress);i > number;i--){
            *(firstAddress+i+1)=*(firstAddress+i);
        }
        *(firstAddress+number+1)=newElem;
    }
}
