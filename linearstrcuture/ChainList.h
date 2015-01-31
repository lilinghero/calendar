#ifndef CHAINLIST_H
#define CHAINLIST_H
#include "List.h"
class ChainList:public List
{
public:


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

    void replaceElem(void* firstAddress,int number,int replacedValue);
    void  swapElem(void* firstAddress,int positionA,int positionB);



    class numChain
    {
    public:
       int member;
       numChain* nextp;
    };
    int locate[12];
};

#endif // CHAINLIST_H
