#include <iostream>
#include "Sorting.h"

using namespace std;

void Sorting::normalSoting(int *firstAddress){
    this->p=&this->lineObject;

    int length=this->p->listLength(firstAddress);
    for(int i=0;i<length;i++){
        for(int k=i+1;k<=length;k++){
            if(p->getElem(firstAddress,i) > p->getElem(firstAddress,k)){
                p->swapElem(firstAddress,i,k);
            }
        }
    }
}

void Sorting::normalSoting(ChainList::numChain *firstAddress){
    this->p=&this->chainObject;
    int length=this->p->listLength(firstAddress);
    for(int i=0;i<length;i++){
        cout<<p->getElem(firstAddress,i)<<"======================"<<endl;
        for(int k=i+1;k<=length;k++){
            cout<<"--------"<<p->getElem(firstAddress,k)<<"-=-=-"<<endl;
            if(p->getElem(firstAddress,i) > p->getElem(firstAddress,k)){
                p->swapElem(firstAddress,i,k);
                cout<<"hello"<<"i="<<p->getElem(firstAddress,i)<<endl<<endl;
            }
        }
    }
}

void Sorting::bubbleSoting(int *firstAddress){
    int booleanValue;

    this->p=&this->lineObject;

    while(booleanValue){
        booleanValue=1;

        for(int i=0;i < p->listLength(firstAddress);i++){
            if(p->getElem(firstAddress,i) > p->getElem(firstAddress,i+1)){
                p->swapElem(firstAddress,i,i+1);
                booleanValue=0;
            }
        }

        if(booleanValue == 0){
            booleanValue=1;
        }else{
            booleanValue=0;
        }
    }
}
void Sorting::bubbleSoting(ChainList::numChain *firstAddress){
    int booleanValue;

    this->p=&this->chainObject;

    for(int k=1; k<2; k++){
        booleanValue=1;

        for(int i=0;i < p->listLength(firstAddress);i++){
            if(p->getElem(firstAddress,i) > p->getElem(firstAddress,i+1)){
                p->swapElem(firstAddress,i,i+1);
                booleanValue=0;
            }else{
            }
        }

        if(booleanValue == 0){
                booleanValue=1;
         }else{
                booleanValue=0;
         }
    }
}
