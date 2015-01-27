#ifndef CHAINLIST_H
#define CHAINLIST_H
#include "List.h"
class ChainList:List
{
public:
    int listEmpty(int* firstAddress);
    int listLength(int* firstAddress);
    int priorElem(int* firstAddress,int number);
    int nextElem(int* firstAddress,int number);
    int getElem(int* firstAddress,int number);
    int locateElem(int* firstAddress,int targetElem);
    //virtual  int listTraverse()=0;

    void clearList(int* firstAddress);
    void putElem(int* firstAddress,int newElem);
    void listInsert(int* firstAddress,int number,int newElem);
    void listDelete(int* firstAddress,int number);
};

#endif // CHAINLIST_H
