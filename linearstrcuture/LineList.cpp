#include "LineList.h"
#include <iostream>
using namespace std;

/*LineList::LineList(){
    this->locate[12]={0};
}*/

int LineList::listEmpty(void *firstAddress){
    int * firstPoint=reinterpret_cast<int*>(firstAddress);
    if(*firstPoint ){
        return 1;
    }else{
        return 0;
    }
}

int LineList::listLength(void *firstAddress){
    int length=0;

    int *firstPoint=reinterpret_cast<int*>(firstAddress);

    if(this->listEmpty(firstPoint)){
        while(*firstPoint != 0){
            firstPoint++;
            length++;
            //cout<<"##"<<endl;
        }
        return length-1;
    }else{
        //return 0;
        cout<<"this is a empty list."<<endl;
    }
}

void LineList::locateElem(void *firstAddress, int targetElem){
    int locateCounter=0;

    int *firstPoint=reinterpret_cast<int *>(firstAddress);

    for(int  number=0;number <= this->listLength(firstAddress);number++){
        if(*(firstPoint+number) == targetElem){
            this->locate[locateCounter]=number;
            locateCounter++;
            //cout<<"$$$$$$$$$$$$$$$$$$"<<endl;
        }
    }
     if(!locateCounter){
         cout<<"not found your targetElem."<<endl;
     }
}

int LineList::priorElem(void *firstAddress, int number){
    int *firstPoint=reinterpret_cast<int*>(firstAddress);
    if(number <= 0||number > this->listLength(firstPoint)){
        cout<<"this is the frist element, or your number out of the length."<<endl;
        //return 0;
    }else{
       return *(firstPoint+number-1);
    }
}

int LineList::nextElem(void *firstAddress, int number){
    int* firstPoint=reinterpret_cast<int*>(firstAddress);

    if(number < 0 || number >= (this->listLength(firstPoint))){;
        cout<<"this is the last element, or your number is  out of the length"<<endl;
        //return 0;
    }else{
        return *(firstPoint+number+1);
    }
}

int LineList::getElem(void *firstAddress, int number){
    int * firstPoint=reinterpret_cast<int*>(firstAddress);

    if(number >= 0 && number <= (this->listLength(firstAddress))){
        return *(firstPoint+number);
    }else{
        cout<<"your number out scope of the list.!!!!!!!!!!!!!!!!!!!!"<<endl;
        //return 0;
    }
}

void LineList::clearList(void *firstAddress){
    int* firstPoint=reinterpret_cast<int*>(firstAddress);

    if(this->listEmpty(firstPoint) == 1){
        for(int i=this->listLength(firstPoint);i >= 0;i--){
            *(firstPoint+i)=0;
        }
    }
}

void LineList::putElem(void *firstAddress, int newElem){
    int * firstPoint=reinterpret_cast<int*>(firstAddress);
    if(this->listEmpty(firstPoint) == 1){
        *(firstPoint+this->listLength(firstPoint)+2)=0;
        *(firstPoint+this->listLength(firstPoint)+1)=newElem;
    }
}

void LineList::listDelete(void*firstAddress,int number){
    int *firstPoint=reinterpret_cast<int*>(firstAddress);
    //cout<<this->listLength(firstAddress)<<endl;
    if(number >= 0 && number <= this->listLength(firstAddress)){
        for( int i=number;i<= this->listLength(firstAddress);i++){
           * (firstPoint+i)=*(firstPoint+i+1);
            cout<<"hello"<<endl;
        }
    }
}

void LineList::listInsert(void *firstAddress, int number,int newElem){
    int *firstPoint=reinterpret_cast<int*>(firstAddress);

    if(number >= 0 && number <= this->listLength(firstPoint)){
        for(int i=this->listLength(firstPoint);i > number;i--){
            *(firstPoint+i+1)=*(firstPoint+i);
        }
        *(firstPoint+number+1)=newElem;
    }
}

void LineList::replaceElem(void *firstAddress, int number, int replacedValue){
    int *firstPoint=reinterpret_cast<int*>(firstAddress);
    *(firstPoint+number)=replacedValue;
}

void LineList::swapElem(void *firstAddress, int positionA, int positionB){
    int *firstPoint=reinterpret_cast<int*>(firstAddress);
    if(positionA >=0 && positionA <= this->listLength(firstPoint) && positionB >= 0 && positionB <= this->listLength(firstPoint)){
        int swapSpace=this->getElem(firstPoint,positionA);
        this->replaceElem(firstPoint,positionA,this->getElem(firstPoint,positionB));
        this->replaceElem(firstAddress,positionB,swapSpace);
    }

}
