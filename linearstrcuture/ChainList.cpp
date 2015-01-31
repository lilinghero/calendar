#include "ChainList.h"
#include <iostream>
using namespace std;


int ChainList::listEmpty(void*firstAddress){
    numChain * firstPoint=reinterpret_cast<numChain*>(firstAddress);
    if(firstPoint->member ){
        return 1;
    }else{
        return 0;
    }
}


int ChainList::listLength(void* firstAddress){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    int counter=0;

    while(firstPoint->nextp != NULL){
        counter++;
        firstPoint= firstPoint->nextp;
    }
    return counter;
}
void ChainList::locateElem(void* firstAddress,int targetElem){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    int locateCounter=0;

    for(int chainCounter=0;chainCounter <= this->listLength(firstAddress);chainCounter++ ){
        if(firstPoint->member == targetElem){
            this->locate[locateCounter]=chainCounter;
            locateCounter++;
        }
        firstPoint=firstPoint->nextp;
    }
    if(!locateCounter){
        cout<<"not found your targetElem."<<endl;
    }
}

int ChainList::getElem(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    if(number <= this->listLength(firstAddress) && number >= 0){
       for(int counter=0;counter <= this->listLength(firstAddress);counter++ ){
            if(number == counter){
                //cout<<firstPoint->member<<"pppppppppppppppppp"<<endl;
                return firstPoint->member;

            }
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list.((((("<<endl;
        //return 0;
    }
}
int ChainList::priorElem(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    if(number <= this->listLength(firstAddress) && number>0){
        for(int counter=0;counter <= this->listLength(firstAddress);counter++ ){
            if(number-counter == 1){
                return firstPoint->member;
            }
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list.*****"<<endl;
        //return 0;
    }
}

int ChainList::nextElem(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    if(number < this->listLength(firstAddress) && number>=0){
        for(int counter=0;counter <= this->listLength(firstAddress);counter++ ){
            if(number-counter == -1){
                return firstPoint->member;
            }
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list.%%%%%"<<endl;
        //return 0;
    }
}

void ChainList::clearList(void *firstAddress){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    if(firstPoint->nextp == NULL){
        cout<<"-------------->"<<firstPoint->member<<endl;
        delete firstPoint;
    }else {
        cout<<"-------------->"<<firstPoint->member<<endl;
        this->clearList(firstPoint->nextp);
        firstPoint->nextp=NULL;
        delete firstPoint;
    }
}

void ChainList::listDelete(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    numChain *p;

    if(number <= this->listLength(firstAddress) && number>0){
        for(int counter=0;counter <= this->listLength(firstAddress);counter++ ){
            if(number-counter == 1){
                p=firstPoint->nextp;
                firstPoint->nextp=firstPoint->nextp->nextp;
                delete p;
                break;
            }
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list.####"<<endl;
        //return 0;
    }
}

void ChainList::putElem(void *firstAddress, int newElem){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    while(1){
        if(firstPoint->nextp == NULL){
            numChain *newMem=new numChain;
            firstPoint->nextp=newMem;
            newMem->member=newElem;
            newMem->nextp=NULL;
            break;
        }
        firstPoint=firstPoint->nextp;
    }
}

void ChainList::listInsert(void *firstAddress, int number, int newElem){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    for(int counter=0;counter <= this->listLength(firstAddress);counter++ ){
        if(number == counter){
            numChain *newMem=new numChain;
            newMem->member=newElem;
            newMem->nextp=firstPoint->nextp;
            firstPoint->nextp=newMem;
            break;
        }
        firstPoint=firstPoint->nextp;
    }
}

void ChainList::replaceElem(void *firstAddress, int number, int replacedValue){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    if(number <= this->listLength(firstAddress) && number >= 0){
        for(int counter=0;counter <= this->listLength(firstAddress);counter++ ){
            if(number == counter){
                firstPoint->member=replacedValue;
                break;
            }
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list.!!!!!!!"<<endl;
        //return 0;
    }
}

void ChainList::swapElem(void *firstAddress, int positionA, int positionB){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    if(positionA >=0 && positionA <this->listLength(firstPoint) && positionB >= 0 && positionB <= this->listLength(firstPoint)){
        int swapSpace=this->getElem(firstPoint,positionA);
        this->replaceElem(firstPoint,positionA,this->getElem(firstPoint,positionB));
        this->replaceElem(firstAddress,positionB,swapSpace);
    }
}

