#ifndef CHAINLIST_H
#define CHAINLIST_H
#include "List.h"
class ChainList:public List
{
public:
    ChainList (){
        this->sum=0;
    }

    int listEmpty(void* firstAddress);
    int listLength(void* firstAddress);
    int priorElem(void* firstAddress,int number);
    int nextElem(void* firstAddress,int number);
    int getElem(void* firstAddress,int number);
    void locateElem(void* firstAddress,int targetElem);

    void clearList(void* firstAddress);
    void putElem(void* firstAddress,int newElem);
    void listInsert(void* firstAddress,int number,int newElem);
    void listDelete(void* firstAddress,int number);

    //struct numChain* listVisit(struct numChain *currentAddress);


    class numChain
    {
    public:
       int member;
       numChain* nextp;
    };
    int locate[12];
    int sum;
};

#endif // CHAINLIST_H
