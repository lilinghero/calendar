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
    int chainCounter=0,locateCounter=0;
    while(1){
        if(firstPoint->member == targetElem){
            this->locate[locateCounter]=chainCounter;
            cout<<locateCounter<<"--->"<<this->locate[locateCounter]<<endl;
            locateCounter++;
        }
        chainCounter++;
        if(firstPoint->nextp == NULL){
            break;
        }
        firstPoint=firstPoint->nextp;
    }
    if(!locateCounter){
        cout<<"not found your targetElem."<<endl;
    }
}

int ChainList::getElem(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    int counter=0;
    if(number <= this->listLength(firstAddress) && number >= 0){
       while(1){
            if(number == counter){
                return firstPoint->member;
            }
            counter++;
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list."<<endl;
        //return 0;
    }
}
int ChainList::priorElem(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    int counter=0;
    if(number <= this->listLength(firstAddress) && number>0){
        while(1){
            if(number-counter == 1){
                return firstPoint->member;
            }
            counter++;
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list."<<endl;
        //return 0;
    }
}

int ChainList::nextElem(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    int counter=0;
    if(number < this->listLength(firstAddress) && number>=0){
        while(1){
            if(number-counter == -1){
                return firstPoint->member;
            }
            counter++;
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list."<<endl;
        //return 0;
    }
}

void ChainList::clearList(void *firstAddress){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);

    if(firstPoint->nextp->nextp == NULL){
        delete firstPoint->nextp;
        firstPoint->nextp=NULL;
        sum=0;
    }else {
        this->sum++;
        cout<<"--->"<<firstPoint->member<<"---->"<<sum<<endl;
        this->clearList(firstPoint->nextp);
        if(sum == 0){
            delete firstPoint->nextp;
            firstPoint->nextp=NULL;
        }
    }
}

void ChainList::listDelete(void *firstAddress, int number){
    numChain* firstPoint=reinterpret_cast<numChain*>(firstAddress);
    int counter=0;
    numChain *p;
    if(number <= this->listLength(firstAddress) && number>0){
        while(1){
            if(number-counter == 1){
                p=firstPoint->nextp;
                firstPoint->nextp=firstPoint->nextp->nextp;
                delete p;
                break;
            }
            counter++;
            firstPoint=firstPoint->nextp;
        }
    }else{
        cout<<"your number out scope of the list."<<endl;
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
    int counter=0;

    while(1){
        if(number == counter){
            numChain *newMem=new numChain;
            newMem->member=newElem;
            newMem->nextp=firstPoint->nextp;
            firstPoint->nextp=newMem;
            break;
        }
         counter++;
        firstPoint=firstPoint->nextp;
    }
}

/*ChainList::numChain* listVisit(ChainList::numChain* currentAddress){
      while(currentAddress->nextp != NULL){
            currentAddress=currentAddress->nextp;
      }
      return currentAddress;
}*.




/*void ChainList::putElem(void *firstAddress, int newElem){
    numChain * firstPoint=reinterpret_cast<numChain*>(firstAddress);
    if(this->listEmpty(firstPoint) == 1){
        numChain *P= new numChain;

        *(firstPoint+this->listLength(firstPoint)+1)=0;
        *(firstPoint+this->listLength(firstPoint))=newElem;
    }
}*/

